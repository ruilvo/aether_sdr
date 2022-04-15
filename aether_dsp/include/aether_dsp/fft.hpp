#pragma once

#include "aether_dsp/fft/impl_base.hpp"
#include "aether_dsp/macros.hpp"

#include <complex>
#include <memory>
#include <span>

namespace aether_dsp::fft
{

enum class Direction
{
    Forward,
    Backward
};

class Fft
{
  public:
    explicit Fft(std::size_t size, Direction direction = Direction::Forward);

    void operator()(std::span<const std::complex<float>> input,
                    std::span<std::complex<float>> output);

  private:
    std::unique_ptr<impl::FftImpl> impl_;
};

} // namespace aether_dsp::fft
