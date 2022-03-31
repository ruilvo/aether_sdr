include_guard(GLOBAL)

# Canonical install dirs
include(GNUInstallDirs)

if(NOT WIN32 AND PROJECT_IS_TOP_LEVEL)
  set(CMAKE_INSTALL_PREFIX "/opt/aether_sdr")
  set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
endif()

set(AETHER_INSTALL_PLUGINDIR "${CMAKE_INSTALL_BINDIR}/plugins")
