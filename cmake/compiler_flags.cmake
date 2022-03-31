include_guard(GLOBAL)

if(NOT AETHER_USE_ISO_FLAGS)
  return()
endif()

if(MSVC)
  add_compile_options("/EHsc" "/volatile:iso" "/Zc:preprocessor" "/Zc:throwingNew"
                      "/Zc:externConstexpr")
endif()
