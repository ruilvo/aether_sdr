#include "aether_dsp/fft/detail/radix2_dit.hpp"

#include "aether_dsp/numbers.hpp"

#include <algorithm>
#include <cassert>
#include <numbers>

namespace aether_dsp::fft::detail
{

namespace
{

/**
 * [1] Lyons, R.; "Understanding Digital Signal Processing", fig. 4.14 (and chapter in
 * general).
 *
 * Using the optimized forms of the butterflies, it's only really necessary to compute the
 * W_M^k up to k=M/2, where M is the current FFT size (2...N). See equation (4-28).
 *
 * An FFT of size N has log2(N) stages. The first stage, where the radix-2 butterfly is
 * used has trivial twiddle factors (1, -1). So it's necessary to compute the twiddle
 * factors for log2(N)-1 stages.
 *
 * The output will have vectors of vectors of twiddle factors, starting with the M=4 @
 * index 0 of the return value.
 *
 * (4-13' from [1]) W_N = exp(j*2*pi*N)
 *
 * (4-28 from [1]) W_N^{k+N/2} = -W_N^k
 */
std::vector<types::fcomplex_buffer_t> computeTwiddleFactors(
    const std::size_t size, const Fft::direction_t direction)
{
    std::vector<types::fcomplex_buffer_t> twiddle_factors;

    const double signal = direction == Fft::direction_t::forward ? -1.0 : 1.0;
    const auto two_pi_n =
        static_cast<float>(signal * 2.0 * std::numbers::pi * static_cast<double>(size));

    for (std::size_t i = 4; i <= size; i *= 2)
    {
        auto &twiddle_factors_m = twiddle_factors.emplace_back();

        for (std::size_t j = 0; j < i / 2; ++j)
        {
            twiddle_factors_m.emplace_back(std::polar<float>(
                1.0F, static_cast<float>(two_pi_n * static_cast<double>(j))));
        }
    }

    return twiddle_factors;
}

} // namespace

Radix2Dit::Radix2Dit(const std::size_t size, const Fft::direction_t direction)
    : size_{size},
      direction_{direction},
      twiddle_factors_{computeTwiddleFactors(size_, direction_)} {};

void Radix2Dit::operator()(const types::fcomplex_span_t input,
                           types::fcomplex_span_t output)
{
    assert(input.size() == output.size());
    assert(input.size() == size_);

    /*
     * 1st stage: radix-2 butterfly (special case)
     * It doesn't do bit-reversal, instead moving index half_index+j into j+1 during the
     * input/output computation.
     */
    const auto half_index = size_ / 2;
    for (std::size_t i = 0; i < size_; i += 2)
    {
        const auto x_in = input[i];
        const auto y_in = input[half_index + 1];
        const auto x_prime = x_in + y_in;
        const auto y_prime = x_in - y_in;
        output[i] = x_prime;
        output[i + 1] = y_prime;
    }
    // Other stages
    const auto n_stages = twiddle_factors_.size();
    for (std::size_t i = 0; i < n_stages; i += 2)
    {
        const auto &twiddle_factors_m = twiddle_factors_[i];
        const auto size_m = twiddle_factors_m.size();
        const auto half_index_k = twiddle_factors_m.size();

        // size_m == size_ (N=8 FFT has 4 factors in the optimized butterfly)
        assert(size_m == size_);
        for (std::size_t j = 0; j < size_m; ++j)
        {
            const auto twiddle_factor_j = twiddle_factors_m[j % size_m];

            const auto x_in = output[j];
            const auto y_wnk = output[half_index_k + j] * twiddle_factor_j;

            const auto x_prime = x_in + y_wnk;
            const auto y_prime = x_in - y_wnk;

            output[j] = x_prime;
            output[half_index_k + j] = y_prime;
        }
    }
}

} // namespace aether_dsp::fft::detail
