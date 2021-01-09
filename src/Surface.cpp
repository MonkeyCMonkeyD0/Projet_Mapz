#include "Surface.hpp"


unsigned int Surface::get_delta_height(const Point& p1, const Point& p2)
{
	return abs((long) (*this)(p2) - (*this)(p1));
}

std::map<unsigned char, Point> Surface::get_neighbors (const Point& p)
{
	size_t C = p.get().first, L = p.get().second;
	std::map<unsigned char, Point> m;
	if (C != 0) {
		m[7] = Point(C-1,L);
		if (L != 0) {
			m[0] = Point(C-1,L-1);
			m[1] = Point(C,L-1);
		}
		if (L != this->get_size().second-1) {
			m[5] = Point(C,L+1);
			m[6] = Point(C-1,L+1);
		}
	}
	if (C != this->get_size().first-1){
		m[3] = Point(C+1,L);
		if (L != 0) {
			m[1] = Point(C,L-1);
			m[2] = Point(C+1,L-1);
		}
		if (L != this->get_size().second-1) {
			m[4] = Point(C+1,L+1);
			m[5] = Point(C,L+1);
		}
	}
	return m;
}

std::map<unsigned char, unsigned int> Surface::get_neighbors_value (const Point& p)
{
	std::map<unsigned char, Point> m = this->get_neighbors(p);
	std::map<unsigned char, unsigned int> vals;
	for (auto i : m)
		vals[i.first] = (*this)(i.second);

	return vals;
}
