#include <iostream>
#include <ciso646>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "Configuracion.h"


int main(int argc, char* argv[]) {
    // Start GLFW context and hint about library

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Start Window
    GLFWwindow* window = glfwCreateWindow(800, 800, titulo_programa.c_str(), NULL, NULL);
    if (window == NULL) {  // Close program if couldn't create window
        std::cerr << "GLFW Window creation failed!!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    while (not glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
