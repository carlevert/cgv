#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifdef __unix__
#include <gtk/gtk.h>
extern "C" {
#include "ass2gui.h"
}
#endif


#include "Application.hpp"



#define BUFFER_OFFSET(i) ((char *)NULL + (i))

Application* application;
void* app;

GLFWwindow* SetupGlfw();
void GlfwErrorCallback(int error, const char* description);
void GlfwWindowCloseCallback(GLFWwindow* window);
void GlfwFramebufferSizeCallback(GLFWwindow* window, int width, int height);
void GlfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void GlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void GlfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

