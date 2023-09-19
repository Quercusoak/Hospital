#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable: 4996)
#pragma warning(disable: 4267)

class StringException 
{
public:
	StringException(string str) noexcept(false)
	{
		if (str == "")
			throw string("cannot accept empty string.");
	}
};


class BoolException
{
public:
	BoolException(unsigned int b) noexcept(false)
	{
		if (b != 0 && b != 1)
			throw string("Choose one of the two options.");
	}
};


class IdException 
{
public:
	IdException( int id) noexcept(false)
	{
		if (id < 1)
			throw string("ID invalid.");
	}
};


#endif