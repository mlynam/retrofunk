cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(retrofunk)

option(test "Build tests" OFF)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(retrofunk ${SOURCE_FILES})

include_directories(core)

add_subdirectory(core)
add_subdirectory(test)

target_link_libraries(retrofunk retrofunk_core)