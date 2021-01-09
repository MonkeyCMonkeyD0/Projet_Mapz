#include "../src/Point.hpp"
#include "../src/Grid.hpp"
#include "../src/Surface.hpp"


int main(int argc, char const *argv[])
{
	Point p1(2,3);
	p1.print(std::cout << std::endl);

	Surface s1(20,10);
	s1.print(std::cout);

	s1(10,5) = 42;
	s1.print(std::cout);

	std::cout << std::endl << s1.get_size().first << " - " << s1.get_size().second << std::endl << std::endl;
	
	std::map<unsigned char, Point> m1 = s1.get_neighbors(Point(0,0));
	for (auto i : m1)
		i.second.print(std::cout << (unsigned int) i.first << "->") << ' ';
	
	std::cout << std::endl;

	std::map<unsigned char, unsigned int> m2 = s1.get_neighbors_value(Point(0,0));
	for (auto i : m2)
		std::cout << (unsigned int) i.first << "->" << i.second << ' ';
	std::cout << std::endl;

	std::cout << "delta height = " << s1.get_delta_height(p1,Point(10,5)) << std::endl;
	std::cout << "delta height = " << s1.get_delta_height(Point(10,5),p1) << std::endl;


	return 0;
}