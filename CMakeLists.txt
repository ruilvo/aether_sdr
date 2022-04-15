cmake_minimum_required(VERSION 3.23)

project(
  AetherSdr
  VERSION 0.1
  LANGUAGES C CXX)

include(CMakeDependentOption)

# Options ------------------------------------------------------------------------------------------

option(BUILD_SHARED_LIBS "Build libraries as shared libraries." OFF)

option(AETHER_DEVELOPER_MODE "Enable developer helpers." OFF)
option(AETHER_BUILD_EXPLORER "Build AetherExplorer." OFF)
cmake_dependent_option(AETHER_BUILD_DSP "Build the AetherDSP library." ON
                       "NOT AETHER_BUILD_EXPLORER" ON)
cmake_dependent_option(AETHER_BUILD_EXTRAS "Build extra stuff (non-required external libs, etc.)."
                       OFF "NOT AETHER_DEVELOPER_MODE" ON)

option(AETHER_SET_CXX_STANDARD "Set the C++ standard directly." ON)
option(AETHER_USE_LTO "Enable link-time optimization when possible." ON)
option(AETHER_USE_FAST_MATH "Use fast math when possible (-ffast-math or /fp:fast)." OFF)
option(AETHER_USE_ISO_FLAGS "Add extra compiler flags to make compilers more compliant." ON)
option(AETHER_USE_X86_HIGH_SIMD
       "Use agressive x86 architecture options (-march=skylake or /arch:AVX2)." OFF)

# --------------------------------------------------------------------------------------------------

include(GenerateExportHeader)
include(CheckCXXCompilerFlag)
include(CheckIPOSupported)
include(GNUInstallDirs)

# Local modules
include(cmake/output_structure.cmake)
include(cmake/install_structure.cmake)
include(cmake/default_visibility.cmake)

include(cmake/compiler_flags/cxx_standard.cmake)
include(cmake/compiler_flags/fast_math.cmake)
include(cmake/compiler_flags/ipo_support.cmake)
include(cmake/compiler_flags/iso_flags.cmake)
include(cmake/compiler_flags/x86_high_simd.cmake)

include(cmake/dependencies/openmp.cmake)
include(cmake/dependencies/qt.cmake)

include(cmake/developer_mode.cmake)

# Projects
add_subdirectory(aether_dsp)
add_subdirectory(aether_explorer)
add_subdirectory(extras)
