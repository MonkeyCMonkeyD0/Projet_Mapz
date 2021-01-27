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
	virtual ~Surface() = 0;

	unsigned int get_delta_height(const Point&, const Point&) const;	
	std::map<unsigned char, Point> get_neighbors (const Point&) const;
	std::map<unsigned char, Point> get_neighbors_filtered (const Point&) const;
	std::map<unsigned char, unsigned int> get_neighbors_value (const Point&) const;

	unsigned int max_delta_value = 150;
};

#endif
