add_subdirectory(include)
add_subdirectory(src)

if(AETHER_DEVELOPER_MODE)
  add_subdirectory(tests)
endif()
