#include "GLFWMenu.hpp"


unsigned char GLFWMenu::next_window = 0;
bool GLFWMenu::onclick = false;
double GLFWMenu::mouse_pos[2] = {0,0};

GLFWMenu::GLFWMenu()
{
	GLFWMenu::next_window = 0;
	// GLFWimage icon[1];
	// icon[0].pixels = SOIL_load_image("../data/gps-device.png", &icon[0].width, &icon[0].height, 0, SOIL_LOAD_RGBA);

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
	glfwSetWindowAspectRatio(this->window, 16, 9);
	glfwSwapInterval(1);
	glfwWindowHint(GLFW_REFRESH_RATE, 24);

	glfwSetErrorCallback(GLFWMenu::error_callback);
	glfwSetWindowCloseCallback(this->window, GLFWMenu::window_close_callback);
	glfwSetKeyCallback(this->window, GLFWMenu::key_callback);
	glfwSetCursorPosCallback(this->window, GLFWMenu::cursor_position_callback);
	glfwSetMouseButtonCallback(this->window, GLFWMenu::mouse_button_callback);

	// glfwSetWindowIcon(this->window, 1, icon);
	// SOIL_free_image_data(icon[0].pixels);

	GLuint title = loadBMP("./data/img/LANDSCAPE-choix.bmp");

	this->onexe();
}

GLFWMenu::~GLFWMenu()
{
	glfwDestroyWindow(this->window);
	glfwTerminate();
	this->window = nullptr;
}


void GLFWMenu::onexe()
{
	while (!glfwWindowShouldClose(this->window)) {
		// Keep running
		int width, height;

		glfwGetFramebufferSize(this->window, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();//load identity matrix

		glColor3f(1,1,1);
		glPointSize(15.0f);
		// glTranslatef(-1,-1,-1);//move forward 4 units

		glBegin(GL_LINE_LOOP); //starts drawing of points
			glVertex2f(-0.75,-0.5);
			glVertex2f(-0.75,0);
			glVertex2f(-0.25,0);
			glVertex2f(-0.25,-0.5);
		glEnd(); //end drawing of points

		glBegin(GL_LINE_LOOP); //starts drawing of points
			glVertex2f(0.75,-0.5);
			glVertex2f(0.75,0);
			glVertex2f(0.25,0);
			glVertex2f(0.25,-0.5);
		glEnd(); //end drawing of points

		glBegin(GL_LINE_LOOP); //starts drawing of points
			glVertex2f(-0.45,0.4);
			glVertex2f(-0.6,0.6);
			glVertex2f(-0.45,0.8);
			glVertex2f(0.45,0.8);
			glVertex2f(0.6,0.6);
			glVertex2f(0.45,0.4);
		glEnd(); //end drawing of points

		glBegin(GL_QUADS); //starts drawing of points
			glVertex2f(-0.45,0.4);
			glVertex2f(-0.45,0.8);
			glVertex2f(0.45,0.8);
			glVertex2f(0.45,0.4);
		glEnd(); //end drawing of points

		glfwSwapBuffers(this->window);
		glfwPollEvents();

		if (GLFWMenu::onclick)
			this->check_next_windows();
	}

	this->~GLFWMenu();
}


// GLuint GLFWMenu::loadBMP(const char * imagepath)
// {
// 	// Data read from the header of the BMP file
// 	unsigned char header[54]; 	// Each BMP file begins by a 54-bytes header
// 	unsigned int dataPos; 		// Position in the file where the actual data begins
// 	unsigned int width, height;
// 	unsigned int imageSize; 	// = width*height*3
// 	// Actual RGB data
// 	unsigned char * data;

// 	// Open the file
// 	FILE * file = fopen(imagepath,"rb");
// 	if (!file) {
// 		std::cerr << "Image could not be opened\n";
// 		this->~GLFWMenu();
// 		exit(EXIT_FAILURE);
// 	}
// 	if (fread(header, 1, 54, file) != 54 || header[0] != 'B' || header[1] != 'M'){ // If not 54 bytes read : problem
// 		std::cerr << "Not a correct BMP file\n";
// 		this->~GLFWMenu();
// 		exit(EXIT_FAILURE);
// 	}

// 	// Read ints from the byte array
// 	dataPos = *(int*) &(header[0x0A]);
// 	imageSize = *(int*) &(header[0x22]);
// 	width = *(int*) &(header[0x12]);
// 	height = *(int*) &(header[0x16]);

// 	// Some BMP files are misformatted, guess missing information
// 	if (imageSize==0) imageSize=width*height*3; 	// 3 : one byte for each Red, Green and Blue component
// 	if (dataPos==0) dataPos=54; 	// The BMP header is done that way

// 	// Create a buffer
// 	data = new unsigned char [imageSize];
// 	// Read the actual data from the file into the buffer
// 	fread(data,1,imageSize,file);
// 	//Everything is in memory now, the file can be closed
// 	fclose(file);

// 	// Create one OpenGL texture
// 	GLuint textureID;
// 	glGenTextures(1, &textureID);
// 	// "Bind" the newly created texture : all future texture functions will modify this texture
// 	glBindTexture(GL_TEXTURE_2D, textureID);
// 	// Give the image to OpenGL
// 	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
// }

void GLFWMenu::error_callback(int error, const char* description)
{
	std::cerr << "Error (" << error << ") : " << description << std::endl;
}

void GLFWMenu::window_close_callback(GLFWwindow* window)
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void GLFWMenu::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void GLFWMenu::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	GLFWMenu::mouse_pos[0] = xpos;
	GLFWMenu::mouse_pos[1] = ypos;
}

void GLFWMenu::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		GLFWMenu::onclick = true;
}

void GLFWMenu::check_next_windows()
{
	int width, height;
	glfwGetWindowSize(this->window, &width, &height);

	GLFWMenu::mouse_pos[0] = 2*GLFWMenu::mouse_pos[0]/width - 1;
	GLFWMenu::mouse_pos[1] = 1 - 2*GLFWMenu::mouse_pos[1]/height;
	GLFWMenu::onclick = false;

	// std::cout << "Mouse Position on click is : (" << GLFWMenu::mouse_pos[0] << ", " << GLFWMenu::mouse_pos[1] << ")" << std::endl;

	if (GLFWMenu::mouse_pos[1] <= 0 && GLFWMenu::mouse_pos[1] >= -0.5) {
		if (GLFWMenu::mouse_pos[0] <= -0.25 && GLFWMenu::mouse_pos[0] >= -0.75) {
			GLFWMenu::next_window = 1;
			glfwSetWindowShouldClose(this->window, GLFW_TRUE);
		}
		if (GLFWMenu::mouse_pos[0] <= 0.75 && GLFWMenu::mouse_pos[0] >= 0.25) {
			GLFWMenu::next_window = 2;
			glfwSetWindowShouldClose(this->window, GLFW_TRUE);
		}
	}

	std::cout << GLFWMenu::next_window << std::endl;
}
