# https://bitbucket.org/jpommier/pffft/src/master/

add_library(pffft fftpack.h fftpack.c pffft.h pffft.c)
set_target_properties(
  pffft PROPERTIES C_VISIBILITY_PRESET "default" CXX_VISIBILITY_PRESET "default"
                   VISIBILITY_INLINES_HIDDEN OFF WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_include_directories(pffft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
if(MSVC)
  set_target_properties(pffft PROPERTIES INTERPROCEDURAL_OPTIMIZATION OFF)
  target_compile_definitions(pffft PRIVATE "_USE_MATH_DEFINES")
  target_compile_options(pffft PRIVATE "/wd4244" "/wd4456" "/wd4244")
endif()

if(NOT BUILD_TESTING)
  return()
endif()

add_executable(test_pffft test_pffft.c)
if(MSVC)
  # "test_pffft.c" uses M_LN2 without including `<math.h>` directly. It expects `pffft.h`
  # to include it instead. I decided to not make `_USE_MATH_DEFINES` `PUBLIC` in the
  # target pffft because sane code should include the headers it needs directly.
  target_compile_definitions(test_pffft PRIVATE "_USE_MATH_DEFINES")
  target_compile_options(test_pffft PRIVATE "/wd4244" "/wd4456" "/wd4244")
endif()
target_link_libraries(test_pffft pffft)

add_test(NAME "PFFFT VS FFTPack" COMMAND test_pffft)
