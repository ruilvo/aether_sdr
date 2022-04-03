#include "aether_dsp/literals.hpp"
#include "aether_dsp/numbers.hpp"

#include <bit>

namespace aether_dsp::numbers
{

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
AETHER_DSP_API std::size_t reverseBits(std::size_t value, std::size_t maximum_value)
{
    using aether_dsp::literals::operator""_sz;

    std::size_t result{};

    // irc://irc.libera.chat/c++-general
    // https://godbolt.org/z/oxj1qMjhd
    // https://godbolt.org/z/nG8G61afe for a crazy look-up table
    // Thanks PJBoy!

    const size_t bit_width = std::bit_width(maximum_value);
    for (size_t sizer{}; sizer < bit_width; ++sizer)
    {
        result = result << 1_sz | (value & 1_sz);
        value >>= 1_sz;
    }

    return result;
}

} // namespace aether_dsp::numbers
