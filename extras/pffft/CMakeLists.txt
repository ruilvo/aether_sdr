# https://bitbucket.org/jpommier/pffft/src/master/

add_library(pffft "fftpack.h" "fftpack.c" "pffft.h" "pffft.c")
set_target_properties(
  pffft PROPERTIES C_VISIBILITY_PRESET "default" CXX_VISIBILITY_PRESET "default"
                   VISIBILITY_INLINES_HIDDEN OFF WINDOWS_EXPORT_ALL_SYMBOLS ON)
if(MSVC)
  target_compile_definitions(pffft PUBLIC _USE_MATH_DEFINES)
endif()

add_executable(test_pffft test_pffft.c)
target_link_libraries(test_pffft pffft)
