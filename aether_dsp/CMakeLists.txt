add_library(aether_dsp)

set_target_properties(aether_dsp PROPERTIES OUTPUT_NAME "AetherSdr"
                                            DEFINE_SYMBOL "AETHER_DSP_EXPORTING")
target_compile_features(aether_dsp PUBLIC cxx_std_20)

generate_export_header(
  aether_dsp
  BASE_NAME
  "aether_dsp"
  EXPORT_MACRO_NAME
  "AETHER_DSP_API"
  EXPORT_FILE_NAME
  include/aether_dsp/api.hpp)

target_include_directories(aether_dsp PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)
target_sources(aether_dsp PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include/aether_dsp/api.hpp)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)
