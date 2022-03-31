#include "aether_dsp/numbers.hpp"

namespace aether_dsp::numbers
{

AETHER_DSP_API bool isPowerOfTwo(std::size_t value)
{
    return (value > 0 && ((value & (value - 1)) == 0));
}

} // namespace aether_dsp::numbers
