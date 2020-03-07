#pragma once
#include <iostream>
#include <vector>
#include "Movie.h"

class Movies
{
private:
	std::vector<Movie> movies;
	bool CheckForMovie(std::string name);
public:
	void AddMovie(Movie&);
	void AddMovie(std::string name, std::string rating, int watched);
	void IncrementView(std::string, int = 1);
	void Display() const;
	Movies();	
	~Movies();
};