find_path(OpenGL_INCLUDE_DIR
          NAMES glew.h 
          PATHS ${CMAKE_SOURCE_DIR}/third_party/opengl/include/GL)

find_library(GLEW32_LIBRARY
             NAMES glew32
             PATHS ${CMAKE_SOURCE_DIR}/third_party/opengl/lib/win/x64)

get_filename_component(OpenGL_LIBRARY_DIR ${GLEW32_LIBRARY} DIRECTORY)

set(OpenGL_LIBRARY "freeglut" "glew32" "glfw3" "OpenGL32")

if(OpenGL_INCLUDE_DIR AND OpenGL_LIBRARY)
    set(OpenGL_FOUND TRUE)
endif()
    
if(OpenGL_FOUND)
    if(NOT OpenGL_FIND_QUIETLY)
        message(STATUS "Found OpenGL Library")
    endif()
else()
    if(OpenGL_FIND_REQUIRED)
        message(FATAL_ERROR "Cound not find OpenGL library")
    endif()
endif()