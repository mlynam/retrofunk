cmake_minimum_required(VERSION 2.8.4)
project(retrofunk)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)

add_executable(retrofunk ${SOURCE_FILES})

include_directories(core)

add_subdirectory(core)
add_subdirectory(test)

target_link_libraries(retrofunk retrofunk_core)
target_compile_features(retrofunk PRIVATE cxx_range_for)