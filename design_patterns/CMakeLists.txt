cmake_minimum_required(VERSION 3.3)

file(GLOB HDRS_FILES *.h)

add_library(design_patterns_lib ${HDRS_FILES})

set_target_properties(design_patterns_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(design_patterns main.cpp)

target_link_libraries(design_patterns design_patterns_lib)

