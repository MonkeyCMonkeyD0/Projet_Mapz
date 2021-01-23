#pragma once
#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>

#include "Point.hpp"


template<typename T>
class Grid {

public:
	// virtual Grid (const std::size_t nbC, const std::size_t nbL, const T&) = 0;
	Grid (const std::size_t nbC, const std::size_t nbL, const T& elem);
	Grid (const std::size_t nbC, const std::size_t nbL) : Grid(nbC,nbL,T()) {}
	Grid (const T& elem) : Grid(1000,1000,elem) {}
	Grid (const Grid*);
	Grid() : Grid(1000,1000,T()) {}
	virtual ~Grid();

	T& operator() (const Point&);
	T operator() (const Point&) const;
	std::ostream& print (std::ostream&) const;
	std::ostream& save (std::ostream&) const;
	std::pair<std::size_t,std::size_t> get_size() const;
	void set_value(const Point&, T);

protected:
	void populate (T (*func) (const Point&));

private:
	T** grid;
	std::size_t nbColumn;
	std::size_t nbLine;

};


template<typename T>
Grid<T>::Grid (const std::size_t nbC, const std::size_t nbL, const T& elem) : nbColumn(nbC), nbLine(nbL)
{
	this->grid = new T* [this->nbColumn];
	for (std::size_t i = 0; i < this->nbColumn; ++i) {
		this->grid[i] = new T [this->nbLine];
		for (std::size_t j = 0; j < this->nbLine; ++j)
			(*this)(Point(i,j)) = elem;
	}
}

template<typename T>
Grid<T>::Grid (const Grid* g) : Grid(g->get_size().first,g->get_size().second)
{
	this->populate(*g);
}


template<typename T>
Grid<T>::~Grid()
{
	for (std::size_t i = 0; i < this->nbColumn; ++i)
		delete[] this->grid[i];
	delete[] this->grid;
	this->grid = NULL;
}


template<typename T>
T& Grid<T>::operator() (const Point& p)
{
	if (p.get().first >= this->nbColumn || p.get().second >= this->nbLine){
		std::cerr << "error: Array index out of bounds" << std::endl;
		exit(1);
	}
	return this->grid[p.get().first][p.get().second];
}

template<typename T>
T Grid<T>::operator() (const Point& p) const
{
	if (p.get().first >= this->nbColumn || p.get().second >= this->nbLine){
		std::cerr << "error: Array index out of bounds" << std::endl;
		exit(1);
	}
	return this->grid[p.get().first][p.get().second];
}


template<typename T>
std::ostream& Grid<T>::print(std::ostream& out) const
{
	for (std::size_t j = 0; j < this->nbLine; ++j) {
		for (std::size_t i = 0; i < this->nbColumn; ++i)
			out << (*this)(Point(i,j)) << " ";
		out << std::endl;
	}
	return out;
}

template<typename T>
std::ostream& Grid<T>::save (std::ostream& out) const
{
	out << this->get_size().first << 'x' << this->get_size().second << std::endl;
	return this->print(out);
}


template<typename T>
std::pair<std::size_t,std::size_t> Grid<T>::get_size() const
{
	return std::make_pair(this->nbColumn, this->nbLine);
}


template<typename T>
void Grid<T>::set_value(const Point& p, T val)
{
	(*this)(p) = val;
}


template<typename T>
void Grid<T>::populate (T (*func) (const Point&))
{
	for (std::size_t i = 0; i < this->nbColumn; ++i)
		for (std::size_t j = 0; j < this->nbLine; ++j){
			Point p(i,j);
			(*this)(p) = (*func)(p);
		}
}

#endif
