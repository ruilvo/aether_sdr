include_guard(GLOBAL)

if(NOT AETHER_DEVELOPER_MODE)
  return()
endif()

if(NOT PROJECT_IS_TOP_LEVEL)
  message(AUTHOR_WARNING "Developer mode is intended for developers of ${PROJECT_NAME}. Ignoring.")
  return()
endif()

# Developer mode define
add_compile_definitions(AETHER_DEVELOPER_MODE)

# Diagnostic flags
if(MSVC)
  set(DIAGNOSTIC_FLAGS "/W4")
else()
  set(DIAGNOSTIC_FLAGS "-Wall" "-Wextra" "-pedantic" "-Wconversion" "-Wsign-conversion")
endif()

foreach(DIAGNOSTIC_FLAG ${DIAGNOSTIC_FLAGS})
  check_cxx_compiler_flag(${DIAGNOSTIC_FLAG} AETHER_HAS_${DIAGNOSTIC_FLAG})
  if(AETHER_HAS_${DIAGNOSTIC_FLAG})
    add_compile_options(${DIAGNOSTIC_FLAG})
  endif()
endforeach()

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Copy the compilation database to the project folder to help with clangd
# Only Make and Ninja (non-multi) are supported to export a compilation
# database.
if((${CMAKE_GENERATOR} MATCHES "Make") OR (${CMAKE_GENERATOR} MATCHES "Ninja$"))
  add_custom_target(
    "aether_sdr-ccc" ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_SOURCE_DIR}
    DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
    VERBATIM)
endif()

# Testing
include(CTest)
