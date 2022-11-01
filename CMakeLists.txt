cmake_minimum_required(VERSION 3.1)

project(talk-cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_SUPPRESS_REGENERATION ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(utils)

add_compile_options(-std=c++11)

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

add_executable("${PROJECT_NAME}"
               "${all_source_file}"
               "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")


# macro(source_group_by_dir source_files)
#     if(MSVC)
#         set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
#         foreach(sgbd_file ${${source_files}})
#             string(REGEX REPLACE ${sgbd_cur_dir}/.∗ \\1 sgbd_fpath ${sgbd_file})
#             string(REGEX REPLACE ".∗/.*" \\1 sgbd_group_name ${sgbd_fpath})
#             string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
#             string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
#             if(sgbd_nogroup)
#                 set(sgbd_group_name "\\")
#             endif(sgbd_nogroup)
#             source_group(${sgbd_group_name} FILES ${sgbd_file})
#         endforeach(sgbd_file)
#     endif(MSVC)
# endmacro(source_group_by_dir)
# source_group_by_dir(all_files)