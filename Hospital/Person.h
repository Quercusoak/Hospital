#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include "BaseFunc.h"
#include <string>
using namespace std;
#pragma warning(disable: 4996)


class Person
{
protected:
	string name;

	Person(const string);

	virtual ~Person() = default;


	void setName(const string name);

public:
	const char* getName()				const { return name.c_str(); }

	virtual void toOS(std::ostream& os) const {}

	friend std::ostream& operator<<(std::ostream& os, const Person& person)
	{
		os << "Name - " << person.name;
		person.toOS(os);
		return os;
	}

};

#endif // !__PERSON_H