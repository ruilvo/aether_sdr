#pragma once

#include "aether_dsp/fft.hpp"
#include "aether_dsp/types.hpp"

namespace aether_dsp::fft::detail
{

class Radix2Dit : public IFftImpl
{
  public:
    Radix2Dit(std::size_t size, Fft::direction_t direction);
    void operator()(std::span<const std::complex<float>> input,
                    std::span<std::complex<float>> output) override;

  private:
    const std::size_t size_;
    const Fft::direction_t direction_;
    const std::vector<std::vector<std::complex<float>>> twiddle_factors_;
};

} // namespace aether_dsp::fft::detail
