#pragma once
#ifndef GLFWLANDSCAPE_HPP
#define GLFWLANDSCAPE_HPP

#define GL_SILENCE_DEPRECATION

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

#include "Landscape.hpp"
#include "Pathfinder.hpp"


class GLFWLandscape {

public:
	GLFWLandscape();
	~GLFWLandscape();

	GLuint loadBMP(const char * imagepath);

private:
	static void error_callback(int error, const char* description);
	static void window_close_callback(GLFWwindow* window);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	void onexe();
	Point ask_point(const char *);
	void on_path_search();
	double * rotation_transform(std::size_t, std::size_t);
	double * rotation_transform(const Point& p);

	Landscape * land;
	Pathfinder * pf;
	GLFWwindow * window;
	static double mouse_pos[2];
	static bool onclick;
	static bool pathtested;
	static bool pathfound;

};

#endif
