#include "GLFWMenu.hpp"


GLFWMenu::GLFWMenu()
{
	glfwSetErrorCallback(GLFWMenu::error_callback);

	if (!glfwInit()) {
		// Initialization failed
		std::cerr << "Error on init\n";
		this->~GLFWMenu();
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	this->window = glfwCreateWindow(1920, 1080, "MAPZ - Menu Window", NULL, NULL);
	if (!this->window) {
		// Window or OpenGL context creation failed
		this->~GLFWMenu();
		std::cerr << "Error while creating window\n";
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(this->window);
	glfwSetKeyCallback(this->window, GLFWMenu::key_callback);
	glfwSwapInterval(1);
	
	this->onexe();
}

GLFWMenu::~GLFWMenu()
{
	glfwDestroyWindow(this->window);
	this->window = nullptr;
	glfwTerminate();
}


void GLFWMenu::onexe()
{
	while (!glfwWindowShouldClose(this->window)) {
		// Keep running
		int width, height;

		glfwGetFramebufferSize(this->window, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES); //starts drawing of points
			// glVertex3f(1.0f,1.0f,1.0f);
			// glVertex3f(-1.0f,-1.0f,0.0f);
			glVertex2f(0.15,0);
			glVertex2f(0,1);
			glVertex2f(-1,-1);
		glEnd();//end drawing of points

		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}

	this->~GLFWMenu();
}


void GLFWMenu::error_callback(int error, const char* description)
{
	std::cerr << "Error (" << error << ") : " << description << std::endl;
}

void GLFWMenu::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}


