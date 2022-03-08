add_executable(fft_benchmark "main.cpp" "benchmark.hpp" "benchmark.cpp")
add_test(NAME: "fft_benchmark" COMMAND: ${CMAKE_CURRENT_BINARY_DIR}/fft_benchmark)
target_link_libraries(fft_benchmark PRIVATE Qt6::Test aether_dsp pffft)
target_include_directories(fft_benchmark PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
