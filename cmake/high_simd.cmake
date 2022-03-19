include_guard(GLOBAL)

if(NOT AETHER_USE_X86_HIGH_SIMD)
  return()
endif()

if(MSVC)
  add_compile_options("/arch:AVX2")
else()
  add_compile_options("-march=skylake")
endif()
