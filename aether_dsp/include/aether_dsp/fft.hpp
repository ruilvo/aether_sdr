#pragma once

#include "aether_dsp/api.hpp"
#include "aether_dsp/types.hpp"

#include <cstddef>

namespace aether_dsp::fft
{

enum class direction_t
{
    forward,
    backward
};

class Fft
{
  public:
    Fft() = delete;
    explicit Fft(std::size_t size, direction_t direction);
};

} // namespace aether_dsp::fft
