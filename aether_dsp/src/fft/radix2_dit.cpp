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
std::vector<types::fcomplex_buffer_t> computeTwiddleFactors(std::size_t size,
                                                            Fft::direction_t direction)
{
    std::vector<types::fcomplex_buffer_t> twiddle_factors;

    const double signal = direction == Fft::direction_t::forward ? -1.0 : 1.0;
    const auto two_pi_n = static_cast<float>(signal * 2.0 * std::numbers::pi_v<double> *
                                             static_cast<double>(size));

    for (std::size_t i = 4; i <= size; i *= 2)
    {
        auto &twiddle_factors_m = twiddle_factors.emplace_back();

        for (std::size_t j = 0; j < i / 2; ++j)
        {
            twiddle_factors_m.emplace_back(
                std::polar(1.0F, two_pi_n * static_cast<float>(j)));
        }
    }

    return twiddle_factors;
}

} // namespace

Radix2Dit::Radix2Dit(std::size_t size, Fft::direction_t direction)
    : size_{size},
      direction_{direction}
{
    computeTwiddleFactors(size_, direction_);
};

void Radix2Dit::operator()(types::fcomplex_span_t input, types::fcomplex_span_t output)
{
    // TODO(ruilvo): actually implement the algorithm
    std::ranges::copy(input, output.begin());
}

} // namespace aether_dsp::fft::detail
