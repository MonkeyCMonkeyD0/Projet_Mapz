#pragma once
#ifndef MAZE_HPP
#define MAZE_HPP

#include "Point.hpp"
#include "Surface.hpp"


class Maze : public Surface {

public:
	Maze (const std::size_t nbC, const std::size_t nbL);
	Maze (const Maze& maze) : Surface(maze) {}

private:
	void generate_maze(const Point& start, const Point& end, bool vertical);
	static unsigned int wall_height;
	static std::default_random_engine generator;

};

#endif