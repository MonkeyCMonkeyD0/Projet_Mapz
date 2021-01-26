#include "Labyrinth.hpp"


unsigned int Labyrinth::wall_height = 1000;

Labyrinth::Labyrinth (const std::size_t nbC, const std::size_t nbL) : Surface(nbC,nbL)
{
	this->max_delta_value = this->wall_height/2;
	this->generator = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
	this->generate_labyrinth(Point(0,0), Point(nbC-1,nbL-1), vertical = TRUE);
	
}

void Labyrinth::generate_labyrinth(const Point& start, const Point& end, bool vertical)
{	
	if(start.dist(Point(start.get().first,end.get().second)) > 2 && end.dist( Point(start.get().first,end.get().second))> 2)
	{
		std::uniform_int_distribution<int> x_distrib(start.get().first+1,end.get().first+1);
		std::uniform_int_distribution<int> y_distrib(start.get().second+1,end.get().second+1);
		x_val = x_distrib(generator);
		y_val = y_distrib(generator);
		if (vertical)
			for(std::size_t i = start.get().second; i <= end.get().second; i++)
				if(i!= y_val)
					this->set_value(Point(x_val, i), Labyrinth::wall_height)
		else
			for(std::size_t i = start.get().first; i <= end.get().first; i++)
				if(i!= x_val)
					this->set_value(Point(i, y_val), Labyrinth::wall_height)

	}
	if(vertical)
		Labyrinth::generate_labyrinth();
	else
		Labyrinth::generate_labyrinth();
	



}