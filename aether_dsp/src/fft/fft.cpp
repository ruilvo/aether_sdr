#include "aether_dsp/fft.hpp"

namespace aether_dsp::fft
{

namespace detail
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
 * @return std::unique_ptr<detail::IFftImpl> A polymorphic object containing the required
 * implementation.
 *
 */
std::unique_ptr<detail::IFftImpl> makeFftImpl(std::size_t size,
                                              Fft::direction_t direction)
{
    // TODO(ruilvo): Implement this function.
    return {};
}

} // namespace detail

Fft::Fft(std::size_t size, direction_t direction)
    : fft_impl_{detail::makeFftImpl(size, direction)} {};

void Fft::operator()(types::fcomplex_span_t input, types::fcomplex_span_t output)
{
    /**
     * The overhead of the indirection should be drowned in the actual computational cost
     * of the FFT.
     */
    (*fft_impl_)(input, output);
}

} // namespace aether_dsp::fft
