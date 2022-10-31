cmake_minimum_required(VERSION 3.1)

project(talk-cpp)

add_compile_options(-std=c++11)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable("${PROJECT_NAME}" "${CMAKE_SOURCE_DIR}/src/main.cpp")