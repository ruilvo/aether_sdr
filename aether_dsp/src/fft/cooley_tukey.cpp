#include "aether_dsp/fft/detail/cooley_tukey.hpp"

#include <algorithm>

namespace aether_dsp::fft::detail
{

CooleyTukeyFftImpl::CooleyTukeyFftImpl(std::size_t size, Fft::direction_t direction){};

void CooleyTukeyFftImpl::operator()(types::fcomplex_span_t input,
                                    types::fcomplex_span_t output)
{
    // TODO(ruilvo): actually implement the algorithm
    std::ranges::copy(input, output.begin());
}

} // namespace aether_dsp::fft::detail
