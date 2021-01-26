#include "Labyrinth.hpp"


unsigned int Labyrinth::wall_height = 1000;

Labyrinth::Labyrinth (const std::size_t nbC, const std::size_t nbL) : Surface(nbC,nbL)
{
	this->max_delta_value = this->wall_height/2;

	
}

Labyrinth::Labyrinth (std::istream&)
{
	
}