#pragma once

#include "aether_dsp/api.hpp"
#include "aether_dsp/types.hpp"

namespace aether_dsp::numbers
{

/**
 * @brief Check whether a number is a power of 2.
 *
 * @param value the number to check the value of.
 * @return bool true if the number is a power of 2, false otherwise. 0 returns false.
 */
AETHER_DSP_API bool isPowerOfTwo(std::size_t value);

/**
 * @brief Reverse the bit representation of a number, considering the
 * bit_width(maximum_value) as the number of bits.
 *
 * @param value value to reverse the bit representation of.
 * @param maximum_value value used to computed the bit-width to use.
 * @return std::size_t the reversed bit representation of the value.
 */
AETHER_DSP_API std::size_t reverseBits(std::size_t value, std::size_t maximum_value);

} // namespace aether_dsp::numbers
