#pragma once

#include <iostream>
#include <cstring>

class Mystring
{
	friend std::ostream &operator<<(std::ostream&, const Mystring&);
	friend std::istream &operator>>(std::istream&, Mystring&);
	friend Mystring operator-(const Mystring&);
	friend Mystring operator+(const Mystring&, const Mystring&);
	friend bool operator==(const Mystring&, const Mystring&);
	friend bool operator!=(const Mystring&, const Mystring&);
	friend bool operator<(const Mystring&, const Mystring&);
	friend bool operator>(const Mystring&, const Mystring&);
	friend Mystring operator+=(Mystring&, const Mystring&);
	friend Mystring operator*(const Mystring&, int);
	friend Mystring operator*=(Mystring&, int);
	friend Mystring &operator++(Mystring&);
	friend Mystring operator++(Mystring&, int);
private:
	char *str;
public:
	Mystring(); // No-args constructor
	Mystring(const char *s); // Overloaded constructor
	Mystring(const Mystring &source); // Copy constructor
	Mystring(Mystring &&source); // Move constructor
	~Mystring(); // Destructor

	void display() const;
	int get_length() const;
	const char *get_str() const;

	Mystring &operator=(const Mystring &rhs); // Copy assignment
	Mystring &operator=(Mystring &&rhs); // Move assignment
};