cmake_minimum_required(VERSION 3.3)

add_library(smart_pointers_lib shared_pointer.h)

set_target_properties(smart_pointers_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(smart_pointers main.cpp)

