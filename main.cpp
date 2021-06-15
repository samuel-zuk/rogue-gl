#include <iostream>
#include <exception>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void fbufWindowResizeCallback(GLFWwindow* window, int width, int height);
void inputHandler(GLFWwindow* window);

int main(int argc, char* argv[]) {
    using namespace std;

    /* Initialization for OpenGL 3.3 Core */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Spawn window w/ res 800x600 */
    GLFWwindow* window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
    if( window == NULL ) {
        glfwTerminate();
        throw runtime_error("GLFW window initialization error.");
    }

    /* Ensure GLAD loaded OpenGL libraries */
    glfwMakeContextCurrent(window);
    if( !gladLoadGLLoader((GLADloadproc) glfwGetProcAddress) ) {
        glfwTerminate(); 
        throw runtime_error("GLAD initialization error");
    }

    /* Set active viewport, attach event handler for window resize */
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, fbufWindowResizeCallback);


    /* Main Render Loop */
    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();

        inputHandler(window);
    }
    
    /* Cleanup */
    glfwTerminate();
    return 0;
}

void fbufWindowResizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void inputHandler(GLFWwindow* window) {
    /* Close when <ESC> is pressed */
    if( glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS )
        glfwSetWindowShouldClose(window, 1);
}
