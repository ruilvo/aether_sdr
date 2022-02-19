set(aether_dsp_sources "placeholder.cpp")
set(aether_dsp_headers "include/aether_dsp/placeholder.hpp")

add_library(aether_dsp ${aether_dsp_headers} ${aether_dsp_sources})
set_target_properties(aether_explorer PROPERTIES OUTPUT_NAME "AetherSdr")
target_include_directories(aether_dsp PUBLIC "include")
