#include <iostream>

#include "GLFWMenu.hpp"
#include "GLFWLandscape.hpp"


int main(int argc, char const *argv[])
{
	GLFWMenu graphic_menu;

	if (GLFWMenu::next_window)
		GLFWLandscape graphic_land;
	else 
		std::cout << "Sorry Maze version is not graphicaly available yet. :(" << std::endl;

	return 0;
}