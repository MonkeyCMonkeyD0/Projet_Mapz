#pragma once
#ifndef GLFWMENU_HPP
#define GLFWMENU_HPP

#define GL_SILENCE_DEPRECATION

#include <GLFW/glfw3.h>
#include <iostream>


class GLFWMenu {

public:
	GLFWMenu();
	~GLFWMenu();

private:
	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void onexe();

	GLFWwindow* window;

};

#endif