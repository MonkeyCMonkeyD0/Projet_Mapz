#pragma once
#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <cmath>
#include <random>
#include <ctime>

#include <FastNoiseLite/FastNoiseLite.h>

#include "Point.hpp"
#include "Surface.hpp"


class Landscape : public Surface {

public:
	Landscape (const std::size_t, const std::size_t);
	Landscape (const Landscape& landscape) : Surface(landscape) {}

	unsigned int get_height_limit() const;

private:
	static unsigned int generate_landscape (const Point&);
	static unsigned int height_limit;
	static FastNoiseLite noise;

};

#endif