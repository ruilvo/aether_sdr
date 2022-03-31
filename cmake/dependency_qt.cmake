include_guard(GLOBAL)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC OFF) # Deprecated

find_package(
  Qt6 6.2
  COMPONENTS Core Quick Gui Test
  REQUIRED)
