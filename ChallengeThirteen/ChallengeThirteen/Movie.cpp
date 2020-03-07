#include <iostream>
#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int timesWatched)
	: name{ name }, rating{ rating }, timesWatched{ timesWatched }
{
}

Movie::Movie(const Movie & source) 
	: Movie(source.name, source.rating, source.timesWatched)
{
}

Movie::~Movie()
{
}

void Movie::Display() const
{
	std::cout << name << ", " << rating << ", " << timesWatched << std::endl;
}
