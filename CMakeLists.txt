cmake_minimum_required(VERSION 3.19)

project(
  AetherSdr
  VERSION 0.1
  LANGUAGES C CXX)

# Options --------------------------------------------------------------------------------

option(BUILD_SHARED_LIBS "Build libraries as shared libraries. CMake variable name." OFF)
option(
  AETHER_DEVELOPER_MODE
  "Enable developer helpers. Requires Qt>6 for and ATHER_BUILD_EXTRAS for tests/benchmarks."
  OFF)
option(AETHER_USE_LTO "Enable link-time optimization when possible" ON)
option(AETHER_USE_FAST_MATH "Use fast math when possible (-ffast-math or /fp:fast)" OFF)
option(AETHER_USE_X86_HIGH_SIMD
       "Use agressive x86 architecture options (-march=skylake or /arch:AVX2)" OFF)
option(AETHER_BUILD_EXPLORER "Build AetherExplorer (requires Qt>6)" OFF)
option(ATHER_BUILD_EXTRAS "Build extra stuff (non-required external libs, etc.)" OFF)

# ----------------------------------------------------------------------------------------

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# CMake
include(GenerateExportHeader)
include(CheckCXXCompilerFlag)
# Local
include(output_structure)
include(install_structure)
include(default_visibility)
include(compiler_flags)
include(high_simd)
include(ipo_support)
include(fast_math)

# Developer mode options
include(developer_mode)

# Dependencies
include(dependency_openmp)
if(AETHER_BUILD_EXPLORER)
  include(dependency_qt)
endif()

# Projects
add_subdirectory(aether_dsp)
if(AETHER_BUILD_EXPLORER)
  add_subdirectory(aether_explorer)
endif()
if(ATHER_BUILD_EXTRAS)
  add_subdirectory(extras)
endif()
