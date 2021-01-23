#include "Landscape.hpp"


unsigned int Landscape::height_limit = 1000;
FastNoiseLite Landscape::noise;

Landscape::Landscape (const std::size_t size) : Surface(size,size)
{
	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(INT_MIN,INT_MAX);

	Landscape::noise = FastNoiseLite(distribution(generator));
	Landscape::noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
	this->populate((unsigned int (*)(const Point&)) this->generate_landscape);
}

unsigned int Landscape::generate_landscape(const Point& p)
{
	return (unsigned int) abs(Landscape::noise.GetNoise((float) p.get().first, (float) p.get().second) * Landscape::height_limit);
}


// void Landscape::diamond_step (Landscape* land, std::vector<Point>* corner, std::uniform_int_distribution<int> distribution, std::default_random_engine generator)
// {
	// // Implementation of the Diamond-square algorithm to generate landscape
	
	// std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	// std::uniform_int_distribution<int> distribution(-Landscape::height_limit/2,Landscape::height_limit/2);

	// std::vector<Point> * corner = new std::vector<Point>{
	// 	Point(0,0),
	// 	Point(land->get_size().first,0),
	// 	Point(0,land->get_size().second),
	// 	Point(land->get_size())
	// };

	// for (auto p : *corner)
	// 	land->set_value(p, (unsigned int) abs(distribution(generator)));


// 	Point center = corner->at(0) + corner->at(3);
// 	center.set(center.get().first/2, center.get().second/2);
// 	unsigned int val = 0;
// 	for (auto p : *corner)
// 		val += (*land)(p);
// 	val /= corner->size();
// 	val = (unsigned int) abs(val + distribution(generator));
// 	val = min(val, Landscape::height_limit);
// 	(*land)(center) = val;
// 	square_step(land,corner,distribution,generator);
// }


// void Landscape::square_step (Landscape* land, std::vector<Point>* corner, std::uniform_int_distribution<int> distribution, std::default_random_engine generator)
// {
	
// }
