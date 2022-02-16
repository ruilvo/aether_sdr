cmake_minimum_required(VERSION 3.19)

project(
  AetherSdr
  VERSION 0.1
  LANGUAGES CXX)

# Options --------------------------------------------------------------------------------

option(AETHER_DEVELOPER_MODE "Enable developer helpers" OFF)

# ----------------------------------------------------------------------------------------

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Local
include(output_structure)
include(install_structure)
include(cpp_options)
include(ipo_support)
include(default_visibility)
# CMake
include(GenerateExportHeader)

# Developer mode options
include(developer_mode)

# Dependencies
include(dependency_qt)

# Projects
add_subdirectory(aether_explorer)
add_subdirectory(aether_dsp)
