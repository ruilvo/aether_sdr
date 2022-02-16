qt_add_executable(aether_explorer "main.cpp")
set_target_properties(aether_explorer PROPERTIES OUTPUT_NAME "AetherExplorer")

target_link_libraries(aether_explorer PRIVATE Qt6::Gui Qt6::Quick)

qt_add_qml_module(
  aether_explorer
  URI
  aether_explorer
  VERSION
  1.0
  QML_FILES
  "main.qml")
