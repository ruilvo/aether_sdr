target_include_directories(aether_dsp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(
  aether_dsp PRIVATE aether_dsp/macros.hpp aether_dsp/types.hpp aether_dsp/numbers.hpp
                     aether_dsp/fft.hpp aether_dsp/fft/radix2_dit.hpp)
