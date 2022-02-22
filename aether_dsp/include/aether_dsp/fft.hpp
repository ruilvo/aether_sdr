#pragma once

#include "aether_dsp/api.hpp"

#include <complex>
#include <cstddef>
#include <span>

class AETHER_DSP_API Radix2Fft
{
  public:
    explicit Radix2Fft(std::size_t size);
    void operator()(std::span<std::complex<float>> input,
                    std::span<std::complex<float>> output);
};
