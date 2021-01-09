#pragma once
#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <map>

#include "Point.hpp"
#include "Grid.hpp"


class Surface : public Grid<unsigned int> {

public:
	Surface (const std::size_t nbC, const std::size_t nbL, const unsigned int & val) : Grid<unsigned int>(nbC,nbL,val) {}
	Surface (const std::size_t nbC, const std::size_t nbL) : Grid<unsigned int>(nbC,nbL) {}
	Surface (const unsigned int & val) : Grid<unsigned int>(val) {}
	Surface (const Surface& surface) : Grid<unsigned int>(surface) {}
	Surface() : Grid<unsigned int>() {}

// protected:
	unsigned int get_delta_height(const Point&, const Point&);
	std::map<unsigned char, Point> get_neighbors (const Point&);
	std::map<unsigned char, unsigned int> get_neighbors_value (const Point&);

};

#endif
