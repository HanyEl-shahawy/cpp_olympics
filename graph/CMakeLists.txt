cmake_minimum_required(VERSION 3.3)

file(GLOB HDRS_FILES *.h)

add_library(graph_lib ${HDRS_FILES})

set_target_properties(graph_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(graph main.cpp)

target_link_libraries(graph graph_lib)

