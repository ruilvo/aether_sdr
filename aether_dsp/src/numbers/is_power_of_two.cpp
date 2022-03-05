#include "aether_dsp/numbers.hpp"

namespace aether_sdr::numbers
{

bool isPowerOfTwo(std::size_t value)
{
    return (value > 0 && ((value & (value - 1)) == 0));
}

} // namespace aether_sdr::numbers
