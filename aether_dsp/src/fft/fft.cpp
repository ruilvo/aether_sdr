#include "aether_dsp/fft.hpp"

namespace aether_dsp::fft
{

namespace detail
{

fft_impl_t chooseFftImpl([[maybe_unused]] std::size_t size,
                         [[maybe_unused]] Fft::direction_t direction)
{
    // TODO: Implement this function
    return {};
}

types::fcomplex_buffer_t computeTwiddleFactors(
    [[maybe_unused]] std::size_t size, [[maybe_unused]] Fft::direction_t direction)
{
    // TODO: Implement this function
    return {};
}

} // namespace detail

Fft::Fft(std::size_t size, direction_t direction)
    : size_{size},
      direction_{direction},
      fft_impl_{detail::chooseFftImpl(size, direction)},
      twiddle_factors_{detail::computeTwiddleFactors(size, direction)} {};

void Fft::operator()(types::fcomplex_span_t input, types::fcomplex_span_t output)
{
    fft_impl_(input, output, twiddle_factors_);
}

} // namespace aether_dsp::fft
