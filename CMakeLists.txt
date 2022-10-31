cmake_minimum_required(VERSION 3.1)

project(talk-cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_SUPPRESS_REGENERATION ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(utils)

add_compile_options(-std=c++11)

set(all_source_file "")

set(src_dir_name "${CMAKE_SOURCE_DIR}/src")

set(dst_dir_name)

GET_SUBDIRECTORY_NAME("${src_dir_name}" dst_dir_name)

foreach(item ${dst_dir_name})
    include_directories("${src_dir_name}/${item}")
    file(GLOB source_items "${src_dir_name}/${item}/*.h"
                          "${src_dir_name}/${item}/*.cpp")
    list(APPEND all_source_file "${source_items}")
    source_group("${item}" FILES "${source_items}")
endforeach()

add_executable("${PROJECT_NAME}" "${all_source_file}"
                                 "${CMAKE_SOURCE_DIR}/src/main.cpp")