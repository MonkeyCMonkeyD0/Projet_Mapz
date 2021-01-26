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
	unsigned int generate_labyrinth(const Point&);
	static unsigned int wall_height;

};

#endif