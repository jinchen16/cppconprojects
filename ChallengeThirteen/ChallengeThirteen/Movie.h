#pragma once
#include <iostream>
#include <string>

class Movie
{
private:
	std::string name;
	std::string rating;
	int timesWatched;
public:
	std::string GetName() const { return name; };
	void SetName(std::string name) { this->name = name; };
	std::string GetRating() const { return rating; };
	void SetRating(std::string rating) { this->rating = rating; };
	int GetTimesWatched() const { return timesWatched; };
	void SetTimesWatched(int times) { this->timesWatched += times; };
	Movie(std::string, std::string, int);
	Movie(const Movie &source);
	~Movie();
	void Display() const;
};