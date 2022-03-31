#include "aether_dsp/fft.hpp"

#include "aether_dsp/fft/radix2_dit.hpp"
#include "aether_dsp/numbers.hpp"

#include <cassert>
#include <stdexcept>

namespace aether_dsp::fft
{

namespace impl
{

/**
 * @brief Factory function for the FFT implementation.
 *
 * This is not the ideal factory pattern. I very much prefer it when you have a factory
 * class with proper self-registration, so it's not necessary to keep adding `if`
 * statements in here. However, to keep this a free function (and completely hidden away
 * from the user), a compromise was necessary.
 *
 * The function takes the the parameters from the `Fft` class and decides on the
 * appropriate algorithm to use.
 *
 * @param size The size of the FFT.
 * @param direction The direction of the FFT.
 * @return std::unique_ptr<impl::IFftImpl> A polymorphic object containing the required
 * implementation.
 *
 */
std::unique_ptr<impl::IFftImpl> makeFftImpl(const std::size_t size,
                                            const Fft::direction_t direction)
{
    if (numbers::isPowerOfTwo(size))
    {
        return std::make_unique<impl::Radix2Dit>(size, direction);
    }
    throw std::invalid_argument("FFT size must be a power of two.");
}

} // namespace impl

/**
 * It would perhaps be interesting, in the future, to have this templated.
 * Something like std::span where you have
 * `template<std::size_t Extent = std::dynamic_extent>`
 * and have the algorithm be determined constexpr'ly.
 */
Fft::Fft(const std::size_t size, const direction_t direction)
    : fft_impl_{impl::makeFftImpl(size, direction)} {};

void Fft::operator()(std::span<const std::complex<float>> input,
                     std::span<std::complex<float>> output)
{
    /**
     * The overhead of the indirection should be drowned in the actual computational cost
     * of the FFT.
     */
    assert(input.size() == output.size());
    (*fft_impl_)(input, output);
}

} // namespace aether_dsp::fft
