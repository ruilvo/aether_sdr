#pragma once

#include "aether_dsp/fft.hpp"

namespace aether_dsp::fft::detail
{

class Radix2Dit : public IFftImpl
{
  public:
    Radix2Dit(std::size_t size, Fft::direction_t direction);
    void operator()(types::fcomplex_span_t input, types::fcomplex_span_t output) override;
};

} // namespace aether_dsp::fft::detail
