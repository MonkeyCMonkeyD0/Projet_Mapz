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

	static unsigned char get_next_window();
	// static GLuint loadBMP(const char * imagepath);

private:
	static void error_callback(int error, const char* description);
	static void window_close_callback(GLFWwindow* window);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	void onexe();
	void check_next_windows();

	GLFWwindow* window;
	static double mouse_pos[2];
	static bool onclick;
	static unsigned char next_window;

};

#endif
