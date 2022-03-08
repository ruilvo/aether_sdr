#include "test_fft.hpp"

#include "aether_dsp/fft.hpp"

#include "pffft.h"

TestFft::TestFft()
{
    const std::vector<std::size_t> sizes{2,    4,     8,     16,    32,
                                         1024, 16384, 32786, 65536, 524288};
    for (const auto size : sizes)
    {
        auto &vec = inputs_.emplace_back(size);
        vec[0] = {1.0F, 1.0F};
    }
}

// For now benchmark the largest size.

void TestFft::benchmarkAether()
{

    const auto size = inputs_.back().size();

    auto input = inputs_.back();
    auto output = input; // Copy to get an array of same size. Yeah lazy I know...

    auto ffter = aether_dsp::fft::Fft(size, aether_dsp::fft::Fft::direction_t::forward);

    QBENCHMARK
    {
        ffter(input, output);
    }
}

void TestFft::benchmarkPffft()
{
    const auto size = inputs_.back().size();

    auto input = inputs_.back();
    auto X = input;
    auto Y = input;
    auto Z = input;

    PFFFT_Setup *s = pffft_new_setup(size, PFFFT_COMPLEX);

    QBENCHMARK
    {
        pffft_transform(s, (float *)X.data(), (float *)Y.data(), (float *)Z.data(),
                        PFFFT_FORWARD);
    }

    pffft_destroy_setup(s);
}
