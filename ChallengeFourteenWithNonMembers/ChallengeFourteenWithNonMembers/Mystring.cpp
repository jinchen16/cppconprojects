#include <iostream>
#include <cstring>
#include "Mystring.h"

// Default constructor
Mystring::Mystring()
{
	str = new char[1];
	*str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
	:str{ nullptr }
{
	if (s == nullptr)
	{
		Mystring();
	}
	else
	{
		size_t length = strlen(s) + 1;
		str = new char[length];
		strcpy_s(str, length, s);
	}
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
	:str{ nullptr }
{
	size_t length = strlen(source.str) + 1;
	str = new char[length];
	strcpy_s(str, length, source.str);
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

// Display
void Mystring::display() const
{
	std::cout << str << std::endl;
}

// Get the length
int Mystring::get_length() const
{
	return strlen(str);
}

// Get the array of chars
const char *Mystring::get_str() const
{
	return str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
	if (this == &rhs)
		return *this;
	delete[] this->str;
	size_t total = strlen(rhs.str) + 1;
	str = new char[total];
	strcpy_s(str, total, rhs.str);
	return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
	if (this == &rhs)
		return *this;
	delete[] this->str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

// Insertion
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
	os << rhs.str;
	return os;
}

// Extraction
std::istream &operator>>(std::istream &is, Mystring &rhs)
{
	char *buff = new char[1000];
	is >> buff;
	rhs = Mystring{ buff };
	delete[] buff;
	return is;
}

// Lowercase
Mystring operator-(const Mystring &obj)
{
	size_t length = strlen(obj.str) + 1;
	char *buff = new char[length];
	strcpy_s(buff, length, obj.str);
	for (size_t i = 0; i < length; i++)
		buff[i] = tolower(buff[i]);
	Mystring tmp{ buff };
	delete[]buff;
	return tmp;
}

// Concatenate
Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
	size_t length = strlen(lhs.str) + strlen(rhs.str) + 1;
	char *buff = new char[length];
	strcpy_s(buff, length, lhs.str);
	strcat_s(buff, length, rhs.str);
	Mystring tmp{ buff };
	delete[] buff;
	return tmp;
}

// Equality
bool operator==(const Mystring &lhs, const Mystring &rhs)
{
	return (strcmp(lhs.str, rhs.str)) == 0;
}

// Different
bool operator!=(const Mystring &lhs, const Mystring &rhs)
{
	return !(lhs == rhs);
}

// Lexically less
bool operator<(const Mystring &lhs, const Mystring &rhs)
{
	return (strcmp(lhs.str, rhs.str)) < 0;
}

// Lexically greater
bool operator>(const Mystring &lhs, const Mystring &rhs)
{
	return (strcmp(lhs.str, rhs.str)) > 0;
}

// Concatenate and assign
Mystring operator+=(Mystring &lhs, const Mystring&rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

// Repeat
Mystring operator*(const Mystring &lhs, int n)
{
	size_t length = strlen(lhs.str) * n + 1;
	char *buff = new char[length];
	strcpy_s(buff, length, lhs.str);
	for (size_t i = 1; i < n; i++)
		strcat_s(buff, length, lhs.str);
	Mystring tmp{ buff };
	delete[] buff;
	return tmp;
}

// Repeat and assign
Mystring operator*=(Mystring &lhs, int n)
{
	lhs = lhs * n;
	return lhs;
}

// Pre-increment
Mystring &operator++(Mystring &lhs)
{
	for (size_t i = 0, length = strlen(lhs.str); i < length; i++)
		lhs.str[i] = toupper(lhs.str[i]);
	return lhs;
}

// Post-increment
Mystring operator++(Mystring &lhs, int)
{
	Mystring tmp{ lhs };
	++lhs;
	return tmp;
}