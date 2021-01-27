#include "Maze.hpp"


unsigned int Maze::wall_height = 1000;
std::default_random_engine Maze::generator = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());

Maze::Maze (const std::size_t nbC, const std::size_t nbL) : Surface(nbC,nbL)
{
	this->max_delta_value = this->wall_height/2;
	this->generate_maze(Point(0,0), Point(nbC-1,nbL-1), vertical = TRUE);	
}

void Maze::generate_maze(const Point& start, const Point& end, bool vertical)
{	
	if (start.dist(Point(start.get().first, end.get().second)) > 2 && end.dist(Point(start.get().first, end.get().second)) > 2) {
		std::uniform_int_distribution<int> x_distrib(start.get().first+1, end.get().first+1);
		std::uniform_int_distribution<int> y_distrib(start.get().second+1, end.get().second+1);
		x_val = x_distrib(Maze::generator);
		y_val = y_distrib(Maze::generator);
		if (vertical)
			for(std::size_t i = start.get().second; i <= end.get().second; i++)
				if(i!= y_val)
					this->set_value(Point(x_val, i), Maze::wall_height)
		else
			for(std::size_t i = start.get().first; i <= end.get().first; i++)
				if(i!= x_val)
					this->set_value(Point(i, y_val), Maze::wall_height)

	this->generate_maze(start, vertical ? Point(x_val-1,end.get().second) : Point(end.get().first,y_val-1), !vertical);
	this->generate_maze(vertical ? Point(x_val+1,start.get().second) : Point(start.get().first,y_val+1), end, !vertical);
	}
}