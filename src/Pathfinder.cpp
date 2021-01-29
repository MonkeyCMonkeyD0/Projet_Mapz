#include "Pathfinder.hpp"



Pathfinder::Pathfinder(const Surface * s, const Point& ps, const Point& pf) : start(ps), finish(pf), surface(s)
{
	this->point_val[ps.toString()] = std::make_pair(0,0);
}

Pathfinder::~Pathfinder()
{
	this->surface = nullptr;
}

void Pathfinder::construct_path(std::vector<Point> closedList)
{
	this->path.clear();
	Point p = this->finish;
	this->path.insert(this->path.begin(),p);

	while (!(p == this->start)) {
		Point next = p;
		for (auto const& x : this->surface->get_neighbors_filtered(p))
			if (this->point_val.find(x.second.toString()) != this->point_val.end() && this->point_val[x.second.toString()].first < this->point_val[next.toString()].first)
					next = x.second;
		p = next;
		this->path.insert(this->path.begin(),p);
	}
}

bool Pathfinder::execute()
{
	auto compare = [&](const Point& p1, const Point& p2) { return this->point_val[p1.toString()].second > this->point_val[p2.toString()].second; };

	std::vector<Point> closedList;
	std::priority_queue<Point, std::vector<Point>, decltype(compare)> openList(compare);
	openList.push(this->start);

	auto isinopenList = [&](const Point& p, double new_cost) {
		std::priority_queue<Point, std::vector<Point>, decltype(compare)> copy = openList;
		while (!copy.empty()) {
			if (copy.top() == p && this->point_val[copy.top().toString()].first <= new_cost)
				return true;
			copy.pop();
		}
		return false;
	};
	
	Point u;
	while (!openList.empty()) {
		u = openList.top();
		openList.pop();
		if (u == this->finish) {
			this->construct_path(closedList);
			return true;
		}

		for (auto const& x : this->surface->get_neighbors_filtered(u)) {
			Point v = x.second;
			unsigned int new_cost = this->point_val[u.toString()].first + 1;//this->surface->get_delta_height(u,v);
			if (find(closedList.begin(),closedList.end(),v) == closedList.end() && !isinopenList(v,new_cost)) {
				this->point_val[v.toString()] = std::make_pair(new_cost, new_cost + v.dist(this->finish));
				openList.push(v);
			}
		}
		closedList.push_back(u);
	}
	return false;
}

std::vector<Point> Pathfinder::get_path() const
{
	return this->path;
}

