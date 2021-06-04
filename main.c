#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void fbufWindowResizeCallback(GLFWwindow* window, int width, int height);
void inputHandler(GLFWwindow* window);

int main(int argc, char* argv[]) {
    /* Initialization for OpenGL 3.3 Core */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
    if( window == NULL ) {
        glfwTerminate();
        err(1, "GLFW window initialization error");
    }
    glfwMakeContextCurrent(window);
    if( !gladLoadGLLoader((GLADloadproc) glfwGetProcAddress) ) {
        glfwTerminate(); 
        err(1, "GLAD initialization error");
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, fbufWindowResizeCallback);

    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();

        inputHandler(window);
    }
    
    glfwTerminate();
    return 0;
}

void fbufWindowResizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void inputHandler(GLFWwindow* window) {
    if( glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS )
        glfwSetWindowShouldClose(window, 1);
}
