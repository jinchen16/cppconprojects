#pragma once
#include <iostream>
#include <cstring>

class Mystring 
{
	friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
	friend std::istream &operator>>(std::istream &is, Mystring &rhs);
private:
	char *str;
public:
	Mystring(); // No-args constructor
	Mystring(const char *s); // Overloaded constructor
	Mystring(const Mystring &source); // Copy constructor
	Mystring(Mystring &&source); // Move constructor
	~Mystring(); // Destructor

	Mystring &operator=(const Mystring &rhs); // Copy assignment
	Mystring &operator=(Mystring &&rhs); // Move assignment

	// Member methods
	Mystring operator-(); // Returns lower version of the object's string
	bool operator==(const Mystring &rhs); // Returns true if the two strings are equal
	bool operator!=(const Mystring &rhs); // Returns true if the tow string are not equal
	bool operator<(const Mystring &rhs); // Returns true if the lhs string is lexically less than the rhs string
	bool operator>(const Mystring &rhs); // Returns true if the lsh string is lexically greater than the rhs string
	Mystring operator+(const Mystring &rhs) const; // Returns an object that concatenates the lhs and rhs
	Mystring operator+=(const Mystring &rhs); // Concatenate the rhs string to the lhs string and store the result in lhs object
	Mystring operator*(int); // Results in a string that is copied n times
	Mystring operator*=(int); // Repeat the stirng on the lhs n times and store the result back in the lhs object

	Mystring &operator++(); // Pre-increment
	Mystring operator++(int); // Post-increment	

	void display() const;

	int get_length() const;
	const char *get_str() const;
};