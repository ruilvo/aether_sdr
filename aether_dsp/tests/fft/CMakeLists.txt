add_executable(fft_tests "main.cpp" "test_fft.hpp" "test_fft.cpp")
add_test(NAME "fft_tests" COMMAND fft_tests)
target_link_libraries(fft_tests PRIVATE Qt6::Test aether_dsp pffft)
target_include_directories(fft_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
