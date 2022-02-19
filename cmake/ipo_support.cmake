include_guard(GLOBAL)

if(NOT AETHER_USE_LTO)
  return()
endif()

include(CheckIPOSupported)
check_ipo_supported(RESULT IPO_SUPPORTED OUTPUT LTO_ERROR)
if(IPO_SUPPORTED)
  message(STATUS "IPO / LTO enabled")
  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
  message(STATUS "IPO / LTO not supported: ${LTO_ERROR}")
endif()
