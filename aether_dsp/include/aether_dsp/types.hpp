#pragma once

#include <complex>
#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>

// https://stackoverflow.com/a/22346651
// NOLINTNEXTLINE(google-runtime-int)
constexpr std::size_t operator"" _sz(unsigned long long value) noexcept
{
    return static_cast<std::size_t>(value);
}
