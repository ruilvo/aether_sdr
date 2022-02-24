#pragma once

#include "aether_dsp/api.hpp"
#include "aether_dsp/types.hpp"

#include <functional>

namespace aether_dsp::fft
{

namespace detail
{

using fft_impl_t =
    std::function<void(types::fcomplex_span_t input, types::fcomplex_span_t output,
                       types::fcomplex_span_t twiddleFactors)>;

} // namespace detail

class AETHER_DSP_API Fft
{
  public:
    enum direction_t
    {
        forward,
        inverse
    };
    explicit Fft(std::size_t size, direction_t direction = forward);
    void operator()(types::fcomplex_span_t input, types::fcomplex_span_t output);

  private:
    std::size_t size_;
    direction_t direction_;
    detail::fft_impl_t fft_impl_;
    types::fcomplex_buffer_t twiddle_factors_;
};

} // namespace aether_dsp::fft
