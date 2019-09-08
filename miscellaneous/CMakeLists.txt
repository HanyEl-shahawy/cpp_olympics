cmake_minimum_required(VERSION 3.3)

file(GLOB HDRS_FILES *.h)

add_library(misc_lib ${HDRS_FILES})

set_target_properties(misc_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(misc main.cpp)

add_executable(double_dispatching double_dispatching.cpp)

target_link_libraries(misc misc_lib)

