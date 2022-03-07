#include "aether_dsp/fft/detail/radix2_dit.hpp"

#include <algorithm>

namespace aether_dsp::fft::detail
{

Radix2Dit::Radix2Dit(std::size_t size, Fft::direction_t direction){};

void Radix2Dit::operator()(types::fcomplex_span_t input, types::fcomplex_span_t output)
{
    // TODO(ruilvo): actually implement the algorithm
    std::ranges::copy(input, output.begin());
}

} // namespace aether_dsp::fft::detail
