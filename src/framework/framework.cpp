#include "framework.h"

#include <iostream>

using namespace std;

namespace CYXDemo {

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        cout << "Received the ESC key, exit now." << endl;
        glfwSetWindowShouldClose(window, true);
    }
}

Framework::Framework(int width, int height, std::string title) {
    m_width = width;
    m_height = height;
    m_title = title;
    m_window = nullptr;
}

Framework::~Framework() {
    Exit();
    cout << "Bye!" << endl;
}

void Framework::Init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);    // mac os
    
    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
    if (!m_window) {
        cout << "Failed to create window." << endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout << "Failed to initialize GLAD" << endl;
        return;
    }

    glViewport(0, 0, m_width, m_height);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

void Framework::Run() {
    Init();
    Startup();
    while(!glfwWindowShouldClose(m_window)) {
        processInput(m_window);

        Render();

        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
}

void Framework::Startup() {

}

void Framework::Exit() {
    m_window = nullptr;
    glfwTerminate();
}
}