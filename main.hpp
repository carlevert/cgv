#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Application.hpp"

const unsigned int INITIAL_WINDOW_WIDTH = 640;
const unsigned int INITIAL_WINDOW_HEIGHT = 480;

Application* application;



GLFWwindow* SetupGlfw();
void GlfwErrorCallback(int error, const char* description);
void GlfwWindowCloseCallback(GLFWwindow* window);
void GlfwFramebufferSizeCallback(GLFWwindow* window, int width, int height);
void GlfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void GlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void GlfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset);