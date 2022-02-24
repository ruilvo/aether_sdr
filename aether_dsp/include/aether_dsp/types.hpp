#pragma once

#include <complex>
#include <cstddef>
#include <span>
#include <vector>

namespace aether_dsp::types
{

using fcomplex_t = std::complex<float>;
using fcomplex_span_t = std::span<fcomplex_t>;
using fcomplex_buffer_t = std::vector<fcomplex_t>;

} // namespace aether_dsp::types
