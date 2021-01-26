#include "Landscape.hpp"


unsigned int Landscape::height_limit = 1000;
FastNoiseLite Landscape::noise;

Landscape::Landscape (const std::size_t nbC, const std::size_t nbL) : Surface(nbC,nbL)
{
	this->max_delta_value = 150;

	std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(INT_MIN,INT_MAX);

	Landscape::noise = FastNoiseLite(distribution(generator));
	Landscape::noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
	this->populate((unsigned int (*)(const Point&)) this->generate_landscape);
}

unsigned int Landscape::generate_landscape(const Point& p)
{
	float value = (float) Landscape::noise.GetNoise((float) p.get().first, (float) p.get().second);
	value += (float) Landscape::noise.GetNoise((float) 2*p.get().first, (float) 2*p.get().second)/2;
	value += (float) Landscape::noise.GetNoise((float) 4*p.get().first, (float) 4*p.get().second)/4;
	value = exp(value)/4.48168907034; 	// e^1.5

	return (unsigned int) (value * Landscape::height_limit);
}
