include_guard(GLOBAL)

set(QT_REQUIRED AETHER_DEVELOPER_MODE OR AETHER_BUILD_EXPLORER)

if(NOT QT_REQUIRED)
  return()
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC OFF) # Deprecated

find_package(
  Qt6 6.2
  COMPONENTS Core Test Gui Widgets Quick
  REQUIRED)
