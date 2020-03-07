/*
* Made by Jin Chen for the Udemy course taught by Frank J. Mitropoulos.
*/
#include <iostream>
#include "Movies.h"

int main()
{
	Movies myMovies;
	myMovies.Display();

	myMovies.AddMovie("Ip Man", "PG", 100);
	myMovies.AddMovie("Little Mermaid", "G", 5);
	myMovies.Display();

	myMovies.IncrementView("Little Mermaid");
	myMovies.Display();

	myMovies.AddMovie("Little Mermaid", "G", 5);
	return 0;
}