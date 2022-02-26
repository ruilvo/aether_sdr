#pragma once

#include "aether_dsp/api.hpp"
#include "aether_dsp/macros.hpp"
#include "aether_dsp/types.hpp"

#include <memory>

namespace aether_dsp::fft
{

namespace detail
{

class IFftImpl
{
  public:
    AETHER_DSP_NO_COPY_MOVE(IFftImpl)
    virtual ~IFftImpl() = default;

    virtual void operator()(types::fcomplex_span_t input, types::fcomplex_span_t output);
};

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
    std::unique_ptr<detail::IFftImpl> fft_impl_;
};

} // namespace aether_dsp::fft
