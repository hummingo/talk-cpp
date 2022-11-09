cmake_minimum_required(VERSION 3.13)

project(talk-cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SUPPRESS_REGENERATION ON)
set(CMAKE_CXX_STANDARD 11)

option(USE_OPENGL "Whether Use OpenGL Library" OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(utils)

set(all_source_file "")
set(src_dir_name "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(dst_dir_name)
GET_SUBDIRECTORY_NAME("${src_dir_name}" dst_dir_name)
foreach(item ${dst_dir_name})
    include_directories("${src_dir_name}/${item}")
    file(GLOB_RECURSE item_files
        RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        ${src_dir_name}/${item}/*.h
        ${src_dir_name}/${item}/*.cpp)
    list(APPEND all_source_file "${item_files}")
    if(MSVC)
        source_group(${item} FILES ${item_files})
        # source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${item_files})
    endif()
endforeach()

if(USE_OPENGL)
    if(MSVC)
        find_package(OpenGL REQUIRED)
    endif()
endif()

add_executable("${PROJECT_NAME}"
               "${all_source_file}"
               "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

if(OpenGL_FOUND)
    target_include_directories("${PROJECT_NAME}"
                               PUBLIC "${OpenGL_INCLUDE_DIR}")
    target_link_directories("${PROJECT_NAME}"
                               PUBLIC "${OpenGL_LIBRARY_DIR}")
    target_link_libraries("${PROJECT_NAME}"
                               "${OpenGL_LIBRARY}")
endif()