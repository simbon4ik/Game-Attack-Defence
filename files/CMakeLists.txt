cmake_minimum_required(VERSION 3.16)
project(lab2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_compile_options(--coverage)
add_link_options(--coverage)

add_subdirectory(tests)

add_executable(prog src/prog.cpp)

target_link_libraries(prog input simple_class operators class)
