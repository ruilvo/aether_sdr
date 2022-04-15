target_sources(
  aether_dsp
  PRIVATE # Misc
          macros.hpp
          types.hpp
          literals.hpp
          # Numbers
          numbers.hpp
          # FFT
          fft.hpp)

add_subdirectory(fft)
