#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>


class Point {

public:
	Point (const std::size_t x, const std::size_t y) : point(std::make_pair(x,y)) {}
	Point (const std::pair<std::size_t,std::size_t> p) : point(p) {}
	Point (const Point& p) : point(p.get()) {}
	Point() : point(std::pair<std::size_t,std::size_t>()) {}

	Point& operator= (const Point&);
	Point operator+ (const Point&);
	Point& operator+= (const Point&);
	Point operator- (const Point&);
	Point& operator-= (const Point&);

	std::pair<std::size_t,std::size_t> get() const;
	void set (const std::size_t, const std::size_t);
	void set (const std::pair<std::size_t,std::size_t>);
	void set (const Point&);
	std::ostream& print(std::ostream&) const;

private:
	std::pair<std::size_t,std::size_t> point;


};

#endif