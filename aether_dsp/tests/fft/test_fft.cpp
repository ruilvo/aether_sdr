#include "test_fft.hpp"

#include "aether_dsp/fft.hpp"

#include "pffft.h"

#include <QDebug>

void TestFft::testSize2Fft()
{
    const std::size_t size = 2;
    aether_dsp::types::fcomplex_buffer_t input{{1.0, 0}, {1.0, 0}};
    auto output = input; // Copy to get a vector with same shape

    aether_dsp::fft::Fft ffter(size, aether_dsp::fft::Fft::forward);

    ffter(input, output);

    // FFT of 1+0j, 1+0j should be 2+0j, 0+0j
    QCOMPARE(output[0], aether_dsp::types::fcomplex_t(2.0, 0.0));
    QCOMPARE(output[1], aether_dsp::types::fcomplex_t(0.0, 0.0));
}

void TestFft::testAgainstPffft()
{
    const std::size_t size = 16;
    aether_dsp::types::fcomplex_buffer_t input(size);

    input[0] = {1.0, 0.0};

    auto output_aether = input; // Copy to get a vector with same shape

    auto scratch_pfft = input;
    auto output_fpfft = input;

    aether_dsp::fft::Fft ffter(size, aether_dsp::fft::Fft::forward);
    ffter(input, output_aether);

    PFFFT_Setup *s = pffft_new_setup(size, PFFFT_COMPLEX);
    pffft_transform(s, (float *)input.data(), (float *)scratch_pfft.data(),
                    (float *)output_fpfft.data(), PFFFT_FORWARD);
    pffft_destroy_setup(s);

    for (std::size_t i = 0; i < size; ++i)
    {
        QCOMPARE(output_aether[i], output_fpfft[i]);
    }
}
