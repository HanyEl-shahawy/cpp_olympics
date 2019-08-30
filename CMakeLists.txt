cmake_minimum_required(VERSION 3.3)
project(cpp_olympics CXX)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

################################
# GTest
################################
add_subdirectory (googletest-master)
add_subdirectory(smart_pointers)
add_subdirectory(dynamic_programming)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(smart_pointers smart_pointers)
################################
# Unit Tests
################################
# Add test cpp file
file(GLOB SRC_FILES test/*.cpp)
add_executable(runUnitTests ${SRC_FILES})
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main smart_pointers_lib)
add_test( runUnitTests runUnitTests )
