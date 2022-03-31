#pragma once

#include "aether_dsp/api.hpp"
#include "aether_dsp/macros.hpp"
#include "aether_dsp/types.hpp"

#include <memory>

namespace aether_dsp::fft
{

namespace impl
{

class IFftImpl
{
  public:
    IFftImpl() = default;
    AETHER_DSP_NO_COPY_MOVE(IFftImpl)
    virtual ~IFftImpl() = default;

    virtual void operator()(std::span<const std::complex<float>> input,
                            std::span<std::complex<float>> output) = 0;
};

} // namespace impl

class AETHER_DSP_API Fft
{
  public:
    enum direction_t
    {
        forward,
        inverse
    };
    explicit Fft(std::size_t size, direction_t direction = forward);
    void operator()(std::span<const std::complex<float>> input,
                    std::span<std::complex<float>> output);

  private:
    AETHER_DSP_SUPPRESS_C4251
    std::unique_ptr<impl::IFftImpl> fft_impl_;
};

} // namespace aether_dsp::fft
