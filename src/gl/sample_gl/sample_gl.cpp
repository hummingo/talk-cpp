#include "sample_gl.h"

#include <iostream>
#include <glew.h>
#include <glfw3.h> 

void window_resized(GLFWwindow* window, int width, int height);
void key_pressed(GLFWwindow* window, int key, int scancode, int action, int mods);
void show_glfw_error(int error, const char* description);

int SampleGL::TestSampleGL()
{
    glfwSetErrorCallback(show_glfw_error);
    if (!glfwInit()) {
        std::cerr << "GLFW Can't Initialize" << '\n';
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(
        800, // width
        600, // height
        "OpenGL Example",
        NULL, NULL);
    if (!window)
    {
        std::cerr << "glfw Create Window Failed!" << '\n';
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, window_resized);
    glfwSetKeyCallback(window, key_pressed);

    glfwSwapInterval(1);
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Glew Can't Initialize" << glewGetErrorString(err) << '\n';
        glfwTerminate();
        exit(-1);
    }

    std::cout << glGetString(GL_VERSION) << '\n';

    int nr_extensions = 0;
    glGetIntegerv(GL_NUM_EXTENSIONS, &nr_extensions);
    for (int i = 0; i < nr_extensions; ++i) {
        std::cout << glGetStringi(GL_EXTENSIONS, i) << '\n';
    }

    glClearColor(0, 0, 1, 1);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void show_glfw_error(int error, const char* description) {
    std::cerr << "Error: " << description << '\n';
}

void window_resized(GLFWwindow* window, int width, int height) {
    std::cout << "Window resized, new window size: " << width << " x " << height << '\n';

    glClearColor(0, 0, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}

void key_pressed(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == 'Q' && action == GLFW_PRESS) {
        glfwTerminate();
        exit(0);
    }
}
