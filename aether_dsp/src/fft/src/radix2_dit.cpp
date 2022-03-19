#include "aether_dsp/fft/radix2_dit.hpp"

#include "aether_dsp/numbers.hpp"

#include <bit>
#include <cassert>
#include <numbers>

namespace aether_dsp::fft::impl
{

namespace radix2_dit
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
std::vector<std::vector<std::complex<float>>> computeTwiddleFactors(
    const std::size_t size, const Fft::direction_t direction)
{
    std::vector<std::vector<std::complex<float>>> twiddle_factors;

    const double signal = direction == Fft::direction_t::forward ? -1.0 : 1.0;
    const auto two_pi_n =
        static_cast<float>(signal * 2.0 * std::numbers::pi * static_cast<double>(size));

    for (std::size_t i = 4; i <= size; i *= 2)
    {
        auto &twiddle_factors_m = twiddle_factors.emplace_back(i / 2);

        for (std::size_t j = 0; j < i / 2; ++j)
        {
            twiddle_factors_m[j] = std::polar<float>(
                1.0F, static_cast<float>(two_pi_n * static_cast<double>(j)));
        }
    }

    return twiddle_factors;
}

std::vector<std::size_t> computeReversedBitOrderIndices(const std::size_t size)
{
    std::vector<std::size_t> reversed_bit_order_indices(size);

    for (std::size_t i = 0; i < size; ++i)
    {
        reversed_bit_order_indices[i] = numbers::reverseBits(i, size - 1_sz);
    }

    return reversed_bit_order_indices;
}

} // namespace radix2_dit

Radix2Dit::Radix2Dit(const std::size_t size, const Fft::direction_t direction)
    : size_{size},
      direction_{direction},
      twiddle_factors_{radix2_dit::computeTwiddleFactors(size_, direction_)},
      reversed_bit_order_indices_{radix2_dit::computeReversedBitOrderIndices(size_)} {};

void Radix2Dit::operator()(std::span<const std::complex<float>> input,
                           std::span<std::complex<float>> output)
{
    assert(input.size() == output.size());
    assert(input.size() == size_);

    // 1st stage: radix-2 butterfly (special case)
    for (std::size_t i = 0; i < size_; i += 2)
    {
        const auto x_idx = reversed_bit_order_indices_[i];
        const auto y_idx = reversed_bit_order_indices_[i + 1];

        const auto x_in = input[x_idx];
        const auto y_in = input[y_idx];

        const auto x_prime = x_in + y_in;
        const auto y_prime = x_in - y_in;

        output[i] = x_prime;
        output[i + 1] = y_prime;
    }
    // Other stages
    const auto n_stages = twiddle_factors_.size();
    for (std::size_t i = 0; i < n_stages; ++i)
    {
        const auto &twiddle_factors_m = twiddle_factors_[i];
        // Optimized butterflies need half the twiddle factors
        const auto fft_half_size_m = twiddle_factors_m.size();
        const auto fft_size_m = fft_half_size_m * 2;

        for (std::size_t j = 0; j < size_; j += fft_size_m)
        {
            for (std::size_t k = 0; k < fft_half_size_m; ++k)
            {
                const auto x_idx = j + k;
                const auto y_idx = j + fft_half_size_m + k;

                const auto x_in = output[x_idx];
                const auto y_wnk = output[y_idx] * twiddle_factors_m[k];

                const auto x_prime = x_in + y_wnk;
                const auto y_prime = x_in - y_wnk;

                output[x_idx] = x_prime;
                output[y_idx] = y_prime;
            }
        }
    }
}

} // namespace aether_dsp::fft::impl
