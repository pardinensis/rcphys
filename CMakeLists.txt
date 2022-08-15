cmake_minimum_required(VERSION 2.8)
set(NAME rcphys)
project(${NAME})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(GLM)
find_package(ZLIB)

aux_source_directory("${CMAKE_SOURCE_DIR}/source" sources)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

add_executable(${NAME} ${sources})

target_link_libraries(${NAME} z)
