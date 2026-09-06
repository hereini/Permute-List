cmake_minimum_required(VERSION 3.15)

project(PermuteList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(PermuteList
    src/permute_list.cpp
    src/generators/heaps_algorithm.cpp
)

target_include_directories(PermuteList PRIVATE "${PROJECT_SOURCE_DIR}")