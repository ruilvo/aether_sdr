#pragma once

#include "aether_dsp/fft.hpp"

namespace aether_dsp::fft::detail
{

class CooleyTukeyFftImpl : public IFftImpl
{
  public:
    CooleyTukeyFftImpl(std::size_t size, Fft::direction_t direction);
    void operator()(types::fcomplex_span_t input, types::fcomplex_span_t output) override;
};

} // namespace aether_dsp::fft::detail
