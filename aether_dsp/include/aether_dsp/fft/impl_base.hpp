#pragma once

#include "aether_dsp/macros.hpp"

#include <complex>
#include <span>

namespace aether_dsp::fft::impl
{

class FftImpl
{
  public:
    FftImpl() = delete;
    AETHER_DSP_NO_COPY_MOVE(FftImpl)
    virtual ~FftImpl() = default;

    virtual void operator()(std::span<const std::complex<float>> input,
                            std::span<std::complex<float>> output) = 0;
};

} // namespace aether_dsp::fft::impl
