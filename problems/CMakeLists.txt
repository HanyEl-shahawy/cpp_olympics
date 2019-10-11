cmake_minimum_required(VERSION 3.3)

file(GLOB HDRS_FILES *.h)

add_library(problems_lib ${HDRS_FILES})

set_target_properties(problems_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(anagram anagram.cpp)
add_executable(frequ_query frequency_query.cpp)

target_link_libraries(anagram problems_lib)

