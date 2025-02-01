cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/tests)

enable_testing()

add_executable(CandleTests
    tests/CandleTest.cpp
    core/candle.cpp
)
target_link_libraries(CandleTests
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(CandleTests)