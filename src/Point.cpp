#include "Point.hpp"


Point& Point::operator= (const Point& p)
{
	this->point = p.get();
	return *this;
}

Point Point::operator+ (const Point& p)
{
	return Point(this->get().first+p.get().first,this->get().second+p.get().second);
}

Point& Point::operator+= (const Point& p)
{
	this->point.first += p.get().first;
	this->point.second += p.get().second;
	return *this;
}

Point Point::operator- (const Point& p)
{
	std::size_t x,y;
	if (this->get().first - p.get().first > 0)
		x = this->point.first - p.get().first;
	else {
		std::cerr << "error: Point coordinates cannot be negative.\n";
		x = 0;
	}
	if (this->get().second - p.get().second > 0)
		y = this->point.second - p.get().second;
	else {
		std::cerr << "error: Point coordinates cannot be negative.\n";
		y = 0;
	}
	return Point(x,y);
}

Point& Point::operator-= (const Point& p)
{
	if (this->get().first - p.get().first > 0)
		this->point.first -= p.get().first;
	else {
		std::cerr << "error: Point coordinates cannot be negative.\n";
		this->point.first = 0;
	}

	if (this->get().second - p.get().second > 0)
		this->point.second -= p.get().second;
	else {
		std::cerr << "error: Point coordinates cannot be negative.\n";
		this->point.second = 0;
	}

	return *this;
}


std::pair<std::size_t,std::size_t> Point::get() const
{
	return this->point;
}

void Point::set (const std::size_t x, const std::size_t y)
{
	this->point = std::make_pair(x,y);
}

void Point::set (const std::pair<std::size_t,std::size_t> p)
{
	this->point = p;
}

void Point::set (const Point& p)
{
	this->point = p.get();
}

std::ostream& Point::print(std::ostream& out) const
{
	return out << '(' << this->point.first << ',' << this->point.second << ')';
}

double Point::dist(const Point& p) const
{
	return sqrt(pow(p.get().first-this->get().first,2)+pow(p.get().second-this->get().second,2));
}
