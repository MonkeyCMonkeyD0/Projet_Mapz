#include "GLFWLandscape.hpp"


double GLFWLandscape::mouse_pos[2] = {0,0};
bool GLFWLandscape::onclick = false;
bool GLFWLandscape::pathfound = false;
bool GLFWLandscape::pathtested = false;

GLFWLandscape::GLFWLandscape() : pf(nullptr)
{
	this->land = new Landscape(100,100);

	if (!glfwInit()) {
		// Initialization failed
		std::cerr << "Error on init\n";
		this->~GLFWLandscape();
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	this->window = glfwCreateWindow(1920, 1080, "MAPZ - Landscape Window", NULL, NULL);
	if (!this->window) {
		// Window or OpenGL context creation failed
		this->~GLFWLandscape();
		std::cerr << "Error while creating window\n";
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->window);
	glfwSetWindowAspectRatio(this->window, 16, 9);
	glfwSwapInterval(1);
	glfwWindowHint(GLFW_REFRESH_RATE, 10);
	glEnable(GL_DEPTH_TEST);

	glfwSetErrorCallback(GLFWLandscape::error_callback);
	glfwSetWindowCloseCallback(this->window, GLFWLandscape::window_close_callback);
	glfwSetKeyCallback(this->window, GLFWLandscape::key_callback);
	glfwSetCursorPosCallback(this->window, GLFWLandscape::cursor_position_callback);
	glfwSetMouseButtonCallback(this->window, GLFWLandscape::mouse_button_callback);

	// GLuint icon = this->loadBMP("data/img/gps-device.bmp");
	// glfwSetWindowIcon(this->window, 1, icon);

	this->onexe();
}

GLFWLandscape::~GLFWLandscape()
{
	glfwDestroyWindow(this->window);
	glfwTerminate();
	this->window = nullptr;

	delete this->land;
	this->land = nullptr;
	delete this->pf;
	this->pf = nullptr;
}


void GLFWLandscape::onexe()
{
	while (!glfwWindowShouldClose(this->window)) {
		// Keep running
		int width, height;

		glfwGetFramebufferSize(this->window, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity(); //load identity matrix

		glColor3f(1,1,1);
		glPointSize(5.0f);
		// glTranslatef(1,1,0); //move forward 4 units

		for (std::size_t i = 0; i < this->land->get_size().first-1; i++){
			for (std::size_t j = 0; j < this->land->get_size().second-1; j++){

				double * coord;

				glBegin(GL_LINE_LOOP);
					coord = rotation_transform(i,j);
					glVertex3f(coord[0], coord[1], coord[2]);
					delete[] coord;
					coord = rotation_transform(i+1,j);
					glVertex3f(coord[0], coord[1], coord[2]);
					delete[] coord;
					coord = rotation_transform(i+1,j+1);
					glVertex3f(coord[0], coord[1], coord[2]);
					delete[] coord;
					coord = rotation_transform(i,j+1);
					glVertex3f(coord[0], coord[1], coord[2]);
					delete[] coord;
				glEnd();

				glBegin(GL_LINE_LOOP);
					coord = rotation_transform(i,j);
					glVertex3f(coord[0], coord[1], coord[2]);
					delete[] coord;
					coord = rotation_transform(i+1,j+1);
					glVertex3f(coord[0], coord[1], coord[2]);
					delete[] coord;
				glEnd();

				glBegin(GL_LINE_LOOP);
					coord = rotation_transform(i+1,j);
					glVertex3f(coord[0], coord[1], coord[2]);
					delete[] coord;
					coord = rotation_transform(i,j+1);
					glVertex3f(coord[0], coord[1], coord[2]);
					delete[] coord;
				glEnd();
			}
		}

		glColor3f(1,0,0);
		if (GLFWLandscape::pathfound) {
			double * coord;
			glBegin(GL_LINE_STRIP);
				for (auto const &p : this->pf->get_path())
					coord = rotation_transform(p);
					glVertex3f(coord[0], coord[1], coord[2]+0.05);
					delete[] coord;
			glEnd();

			// glBegin(GL_POINTS);
			// 	for (auto const &p : this->pf->get_path())
			// 		coord = rotation_transform(p);
			// 		glVertex3f(coord[0], coord[1], coord[2]-0.06);
			// 		delete[] coord;
			// glEnd();
		}

		glfwSwapBuffers(this->window);
		glfwPollEvents();

		if (GLFWLandscape::onclick) {
			GLFWLandscape::onclick = false;
			this->on_path_search();
		}
	}

	this->~GLFWLandscape();
}

double * GLFWLandscape::rotation_transform(std::size_t i, std::size_t j)
{
	double x = 2.0*i/this->land->get_size().first - 1; 
	double y = 2.0*j/this->land->get_size().second - 1;
	double z = fmin(2.0*(*this->land)(Point(i,j))/this->land->get_height_limit() - 1, 1.0);
	double s = 0.8;
	double * vect = new double[3];
	vect[0]	= x/2 - y*sqrt(2)/2 + z/2;
	vect[1] = x/2 + y*sqrt(2)/2 + z/2;
	vect[2] = (z-x)*sqrt(2)/2;
	vect[0] *= s;
	vect[1] *= s;
	vect[2] *= s;
	return (double *) vect;
}

double * GLFWLandscape::rotation_transform(const Point& p)
{
	return this->rotation_transform(p.get().first, p.get().second);
}


void GLFWLandscape::error_callback(int error, const char* description)
{
	std::cerr << "Error (" << error << ") : " << description << std::endl;
}

void GLFWLandscape::window_close_callback(GLFWwindow* window)
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void GLFWLandscape::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void GLFWLandscape::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);

	GLFWLandscape::mouse_pos[0] = 2*xpos/width - 1;
	GLFWLandscape::mouse_pos[1] = 1 - 2*ypos/height;
}

void GLFWLandscape::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		GLFWLandscape::onclick = true;
}

Point GLFWLandscape::ask_point(const char * str)
{
	std::size_t x,y;
	std::cout << "What is the x value of the " << str << " point? (Between 0 and " << this->land->get_size().first << ") : ";
	std::cin >> x;
	std::cout << "What is the y value of the " << str << " point? (Between 0 and " << this->land->get_size().second << ") : ";
	std::cin >> y;
	if (x < this->land->get_size().first && y < this->land->get_size().second)
		return Point(x,y);
	else {
		std::cout << std::endl << "Wrong given value, please start again." << std::endl;
		return ask_point(str);
	}
}

void GLFWLandscape::on_path_search()
{
	if (!GLFWLandscape::pathtested) {
		GLFWLandscape::pathtested = true;
		this->pf = new Pathfinder(this->land, ask_point("start"), ask_point("end"));
		GLFWLandscape::pathfound = this->pf->execute();
		if (!GLFWLandscape::pathfound)
			std::cerr << "No path between start and finish could be found." << std::endl;
		else 
			std::cout << "Found a path in " << this->pf->get_path().size() << " steps." << std::endl;
	}
}