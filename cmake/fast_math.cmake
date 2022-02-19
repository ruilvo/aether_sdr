include_guard(GLOBAL)

if(NOT AETHER_USE_FAST_MATH)
  return()
endif()

if(MSVC)
  add_compile_options("/fp:fast")
else()
  add_compile_options("-ffast-math")
endif()
