#pragma once

#include "aether_dsp/fft.hpp"
#include "aether_dsp/fft/impl_base.hpp"

#include <memory>

namespace aether_dsp::fft::impl
{

std::unique_ptr<impl::FftImpl> makeFftImpl(std::size_t size, Direction direction);

} // namespace aether_dsp::fft::impl
