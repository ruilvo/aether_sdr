add_library(aether_dsp)

set_target_properties(aether_dsp PROPERTIES OUTPUT_NAME "AetherSdr")
set_target_properties(aether_dsp PROPERTIES DEFINE_SYMBOL "AETHER_DSP_EXPORTING")

generate_export_header(
  aether_dsp
  BASE_NAME
  "aether_dsp"
  EXPORT_MACRO_NAME
  "AETHER_DSP_API"
  EXPORT_FILE_NAME
  "include/aether_dsp/api/api.hpp")

target_include_directories(aether_dsp PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/include"
                                             "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_sources(aether_dsp PRIVATE "include/aether_dsp/placeholder.hpp")
target_sources(aether_dsp PRIVATE "placeholder.cpp")
