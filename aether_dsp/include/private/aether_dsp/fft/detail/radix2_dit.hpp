#pragma once

#include "aether_dsp/fft.hpp"
#include "aether_dsp/types.hpp"

namespace aether_dsp::fft::detail
{

class Radix2Dit : public IFftImpl
{
  public:
    Radix2Dit(std::size_t size, Fft::direction_t direction);
    void operator()(types::fcomplex_span_t input, types::fcomplex_span_t output) override;

  private:
    const std::size_t size_;
    const Fft::direction_t direction_;
    const std::vector<types::fcomplex_buffer_t> twiddle_factors_;
};

} // namespace aether_dsp::fft::detail
