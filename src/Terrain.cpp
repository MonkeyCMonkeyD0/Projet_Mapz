#include "Terrain.hpp"


Terrain::Terrain (const std::size_t nbC, const std::size_t nbL) : Surface(nbC,nbL)
{
	this->populate(this->generate_terrain);
	// this->populate([](const Point& p) -> unsigned int { return generate_terrain(p); });
}

// unsigned int Terrain::(*generate_terrain)(const Point& p)
// {
// 	unsigned int lastval;
// 	if (p.get().first != 0)
// 		lastval = (*this)(Point(p.get().first,p.get().second-1));
// 	else {
// 		if (p.get().second != 0)
// 			lastval = (*this)(Point(p.get().first-1,p.get().second));
// 		else
// 			lastval = this->height_limit/2;
// 	}

// 	std::default_random_engine generator;
// 	std::normal_distribution<unsigned int> distribution(lastval,10.0);
// 	unsigned int res = distribution(generator);

// 	std::cout << res << std::endl;

// 	return std::min(this->height_limit, res);
// }
