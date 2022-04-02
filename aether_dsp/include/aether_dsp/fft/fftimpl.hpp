#pragma once

#include "aether_dsp/fft.hpp"
#include "aether_dsp/macros.hpp"

#include <cstddef>
#include <memory>

namespace aether_dsp::fft::impl
{

class FftImpl
{
  public:
    AETHER_DSP_NO_COPY_MOVE(FftImpl)
    virtual ~FftImpl() = default;

    virtual void operator()(std::span<const std::complex<float>> input,
                            std::span<std::complex<float>> output) = 0;
};

std::unique_ptr<FftImpl> makeFftImpl(std::size_t size, direction_t direction);

}; // namespace aether_dsp::fft::impl
