#pragma once
#ifndef PATHFINDER_HPP
#define PATHFINDER_HPP

#include <vector>
#include <queue>

#include "Point.hpp"
#include "Surface.hpp"


class Pathfinder {

public:
	Pathfinder(const Surface *, const Point&, const Point&);
	~Pathfinder();

	bool execute();
	std::vector<Point> get_path() const;

public:
	Point start, finish;
	const Surface * surface;
	std::map<std::string, std::pair<unsigned int,double>> point_val;
	std::vector<Point> path;

	void construct_path(std::vector<Point> closedList);

};


#endif