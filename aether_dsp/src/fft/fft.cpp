#include "aether_dsp/fft.hpp"

#include "aether_dsp/fft/impl.hpp"

namespace aether_dsp::fft
{

Fft::Fft(size_t size, direction_t direction) : impl_(impl::makeFftImpl(size, direction))
{
}

void Fft::operator()(std::span<const std::complex<float>> input,
                     std::span<std::complex<float>> output)
{
    (*impl_)(input, output);
}

} // namespace aether_dsp::fft
