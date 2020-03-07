#include <iostream>
#include <vector>
#include "Movies.h"

void Movies::AddMovie(Movie &movie)
{
	if (CheckForMovie(movie.GetName())) return;
	movies.push_back(movie);
	std::cout << "Movie " << movie.GetName() << " added\n";
}

void Movies::AddMovie(std::string name, std::string rating, int watched)
{
	if (CheckForMovie(name)) return;
	Movie movie = Movie(name, rating, watched);
	movies.push_back(movie);
	std::cout << "Movie " << movie.GetName() << " added\n";
}

bool Movies::CheckForMovie(std::string name) 
{
	for (Movie &movie : movies)
	{
		if (movie.GetName() == name)
		{
			std::cout << name << " is already in the list\n";
			return true;
		}
	}
	return false;
}

void Movies::IncrementView(std::string name, int times)
{
	for (Movie &movie : movies)
	{
		if (movie.GetName() == name)
		{
			movie.SetTimesWatched(times);
			break;
		}
	}
}

void Movies::Display() const
{
	std::cout << "\n=======================\n";	
	size_t length = movies.size();
	if (length > 0) 
	{
		for (const Movie &movie : movies)
		{
			movie.Display();
		}
	}
	else 
	{
		std::cout << "No movies saved\n";
	}
	std::cout << "=======================\n";
}

Movies::Movies()
{
}

Movies::~Movies()
{
}
