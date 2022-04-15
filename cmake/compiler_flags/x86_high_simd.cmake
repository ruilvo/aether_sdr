include_guard(GLOBAL)

if(NOT AETHER_USE_X86_HIGH_SIMD)
  return()
endif()

if(MSVC)
  set(HIGHSIMD_FLAG "/arch:AVX2")
else()
  set(HIGHSIMD_FLAG "-march=skylake")
endif()

check_cxx_compiler_flag(${HIGHSIMD_FLAG} AETHER_HAS_X86_HIGH_SIMD)

if(AETHER_HAS_X86_HIGH_SIMD)
  add_compile_options(${HIGHSIMD_FLAG})
endif()
