include_guard(GLOBAL)

if(NOT AETHER_DEVELOPER_MODE)
  return()
endif()

if(NOT PROJECT_IS_TOP_LEVEL)
  message(
    AUTHOR_WARNING
      "Developer mode is intended for developers of ${PROJECT_NAME}. Ignoring.")
  return()
endif()

# Diagnostic flags
if(MSVC)
  add_compile_options("/W4")
else()
  add_compile_options("-Wall" "-Wextra" "-pedantic" "-Wconversion" "-Wsign-conversion")
endif()

# Developer mode define
add_compile_definitions(AETHER_DEVELOPER_MODE)

# Testing
include(CTest)

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Copy the compilation database to the project folder to help with clangd
# Only Make and Ninja (non-multi) are supported to export a compilation
# database.
if(("${CMAKE_GENERATOR}" MATCHES "Make") OR ("${CMAKE_GENERATOR}" MATCHES "Ninja$"))
  add_custom_target(
    "aether_sdr-ccc" ALL ${CMAKE_COMMAND} -E copy_if_different
                         ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR})
endif()
