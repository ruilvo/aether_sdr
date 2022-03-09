#pragma once

#include "aether_dsp/api.hpp"
#include "aether_dsp/types.hpp"

namespace aether_dsp::numbers
{

AETHER_DSP_API bool isPowerOfTwo(std::size_t value);

AETHER_DSP_API std::size_t reverseBits(std::size_t value, std::size_t maximum_value);

} // namespace aether_dsp::numbers
