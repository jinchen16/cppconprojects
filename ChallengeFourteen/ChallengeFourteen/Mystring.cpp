#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
	:str{ nullptr }
{
	str = new char[1];
	*str = '\0';
}

// Overload constructor
Mystring::Mystring(const char * s)
	:str{ nullptr }
{
	if (s == nullptr)
	{
		Mystring();
	}
	else
	{
		str = new char[strlen(s) + 1];
		strcpy_s(str, strlen(s) + 1, s);
	}
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
	: str{ nullptr }
{
	str = new char[strlen(source.str) + 1];
	strcpy_s(str, strlen(source.str) + 1, source.str);
}

// Move constructor
Mystring::Mystring(Mystring &&source)
	:str{ source.str }
{
	source.str = nullptr;
}

// Destructor
Mystring::~Mystring()
{
	delete[] str;
}

// Copy assignment
Mystring & Mystring::operator=(const Mystring &rhs)
{
	if (this == &rhs)
		return *this;
	delete[] this->str;
	size_t total = strlen(rhs.str) + 1;
	str = new char[total];
	strcpy_s(this->str, total, rhs.str);
	return *this;
}

// Move assignment
Mystring & Mystring::operator=(Mystring &&rhs)
{
	if (this == &rhs)
		return *this;
	delete[] this->str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

void Mystring::display() const
{
	std::cout << str << std::endl;
}

int Mystring::get_length() const { return strlen(str); }

const char * Mystring::get_str() const { return str; }

// Insertion operator overloading
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
	os << rhs.str;
	return os;
}

// Extraction operator overloading
std::istream &operator>>(std::istream &is, Mystring &rhs)
{
	char *buff = new char[1000];
	is >> buff;
	rhs = Mystring{ buff };
	delete[] buff;
	return is;
}

// Returns lower version of the object's string
Mystring Mystring::operator-()
{
	char *buff = new char[strlen(str) + 1];
	strcpy_s(buff, strlen(str) + 1, str);
	for (size_t i = 0, length = strlen(buff); i < length; i++)
		buff[i] = tolower(buff[i]);
	Mystring temp{ buff };
	delete[] buff;
	return temp;
}

// Returns true if the two strings are equal
bool Mystring::operator==(const Mystring &rhs)
{
	return strcmp(str, rhs.str) == 0;
}

// Returns true if the tow string are not equal
bool Mystring::operator!=(const Mystring &rhs)
{
	return strcmp(str, rhs.str) != 0;
}

// Returns true if the lhs string is lexically less than the rhs string
bool Mystring::operator<(const Mystring &rhs)
{
	return strcmp(str, rhs.str) < 0;
}

// Returns true if the lsh string is lexically greater than the rhs string
bool Mystring::operator>(const Mystring &rhs)
{
	return strcmp(str, rhs.str) > 0;
}

// Returns an object that concatenates the lhs and rhs
Mystring Mystring::operator+(const Mystring &rhs) const
{
	size_t total = strlen(rhs.str) + strlen(str) + 1;
	char *buff = new char[total];
	strcpy_s(buff, total, str);
	strcat_s(buff, total, rhs.str);
	Mystring temp{ buff };
	delete[] buff;
	return temp;
}

// Concatenate the rhs string to the lhs string and store the result in lhs object
Mystring Mystring::operator+=(const Mystring &rhs)
{	
	*this = *this + rhs.str;
	return *this;
}

// Results in a string that is copied n times
Mystring Mystring::operator*(int n)
{
	size_t total = strlen(str) * n + 1;
	char *buff = new char[total];
	strcpy_s(buff, total, str);	
	for (size_t i = 1; i < n; i++)
		strcat_s(buff, total, str);
	Mystring temp{ buff };
	delete[] buff;
	return temp;
}

// Repeat the stirng on the lhs n times and store the result back in the lhs object
Mystring Mystring::operator*=(int n)
{
	*this = *this * n;
	return *this;
}

Mystring &Mystring::operator++() // Pre-increment
{
	// Do whatever you want increment do to - maybe make all characters uppercase...	
	for (size_t i = 0, length = strlen(str); i < length; i++)
		str[i] = toupper(str[i]);	
	return *this;
};

Mystring Mystring::operator++(int) // Post-increment
{
	Mystring tmp(*this); // Make copy
	operator++();
	return tmp;
}