#include "../src/Point.hpp"
#include "../src/Grid.hpp"
#include "../src/Surface.hpp"
#include "../src/Landscape.hpp"
#include "../src/Pathfinder.hpp"

#include <random>
#include <ctime>


int main(int argc, char const *argv[])
{
	// -------------------- TEST POINT --------------------
	// Point p1(2,3);
	// p1.print(std::cout << std::endl);

	// Surface s1(20,10);
	// s1.print(std::cout);

	// s1(Point(10,5)) = 42;
	// s1.print(std::cout);

	// std::cout << std::endl << s1.get_size().first << " - " << s1.get_size().second << std::endl << std::endl;
	
	// std::map<unsigned char, Point> m1 = s1.get_neighbors(Point(0,0));
	// for (auto i : m1)
	// 	i.second.print(std::cout << (unsigned int) i.first << "->") << ' ';
	
	// std::cout << std::endl;

	// std::map<unsigned char, unsigned int> m2 = s1.get_neighbors_value(Point(0,0));
	// for (auto i : m2)
	// 	std::cout << (unsigned int) i.first << "->" << i.second << ' ';
	// std::cout << std::endl;

	// std::cout << "delta height = " << s1.get_delta_height(p1,Point(10,5)) << std::endl;
	// std::cout << "delta height = " << s1.get_delta_height(Point(10,5),p1) << std::endl;


	// -------------------- TEST --------------------
	// std::default_random_engine gene(std::chrono::system_clock::now().time_since_epoch().count());
	// std::uniform_int_distribution<int> distribution(-50,50);
	// for (int i = 0; i < 100; ++i)
	// 	std::cout << (unsigned int) abs(distribution(gene)) << " ";

	// std::pair<int,int> a(2,4);
	// a = a/2;
	// std::cout << a.first << " - " << a.second << std::endl;



	// -------------------- TEST NOISEMAP --------------------
	// float** noiseData = new float*[10];
	// for(int i = 0; i < 10; ++i)
	// 	noiseData[i] = new float[10];

	// for (int y = 0; y < 10; y++)
	// {
	// 	for (int x = 0; x < 10; x++)
	// 	{
	// 		noiseData[x][y] = Landscape::noise.GetNoise((float) x+std::chrono::system_clock::now().time_since_epoch().count(), (float) y+std::chrono::system_clock::now().time_since_epoch().count());
	// 		std::cout << noiseData[x][y] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	// delete[] noiseData;

	// -------------------- TEST LANDSCAPE --------------------
<<<<<<< HEAD
	Landscape land(50);
	land.print(std::cout);
=======
	Landscape land(1000,1000);
	land.print(std::cout) << std::endl;

	Pathfinder pf(&land, Point(1,1), Point(5,15));
	bool isexec = pf.execute();

	if (isexec)
		for (auto i : pf.get_path())
			i.print(std::cout) << " - ";
	std::cout << std::endl;
>>>>>>> 5878e079c6c3ce376e55176ec9c8e5a7566d0bcd

	return 0;
}