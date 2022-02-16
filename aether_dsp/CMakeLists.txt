set(aether_dsp_sources "placeholder.cpp")
set(aether_dsp_headers "include/aether_dsp/placeholder.hpp")

add_library(aether_dsp ${aether_dsp_headers} ${aether_dsp_sources})
target_include_directories(aether_dsp PUBLIC "include")
