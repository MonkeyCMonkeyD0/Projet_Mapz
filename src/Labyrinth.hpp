#pragma once
#ifndef LABYRINTH_HPP
#define LABYRINTH_HPP

#include "Point.hpp"
#include "Surface.hpp"


class Labyrinth : public Surface {

public:
	Labyrinth (const std::size_t nbC, const std::size_t nbL);
	Labyrinth (const Labyrinth& labyrinth) : Surface(labyrinth) {}

private:
	void generate_labyrinth(const Point& start, const Point& end, bool vertical);
	static unsigned int wall_height;
	std::default_random_engine generator;

};

#endif