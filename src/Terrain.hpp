#pragma once
#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <random>

#include "Point.hpp"
#include "Surface.hpp"


class Terrain : public Surface {

public:
	Terrain (const std::size_t nbC, const std::size_t nbL);
	Terrain (const Terrain& terrain) : Surface(terrain) {}

private:
	unsigned int (*generate_terrain) (const Point&);
	// unsigned int height_limit = 100;

};

#endif