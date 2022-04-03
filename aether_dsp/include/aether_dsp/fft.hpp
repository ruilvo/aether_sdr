#pragma once

#include "aether_dsp/api.hpp"
#include "aether_dsp/macros.hpp"
#include "aether_dsp/types.hpp"

#include <complex>
#include <cstddef>
#include <memory>
#include <span>

namespace aether_dsp::fft
{

namespace impl
{

class FftImpl;

} // namespace impl

enum class direction_t
{
    forward,
    backward
};

class Fft
{
  public:
    Fft() = delete;
    Fft(std::size_t size, direction_t direction);
    // To make clang-tidy happy because of the explicitely declared destructor.
    Fft(const Fft &) = delete;
    Fft &operator=(const Fft &) = delete;
    Fft(Fft &&) = default;
    Fft &operator=(Fft &&) = default;
    // To allow for unique_ptr<FftImpl>, when FftImpl is an incomplete type.
    ~Fft() = default;

    void operator()(std::span<const std::complex<float>> input,
                    std::span<std::complex<float>> output);

  private:
    std::unique_ptr<impl::FftImpl> impl_;
};

} // namespace aether_dsp::fft
