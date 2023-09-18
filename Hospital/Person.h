#ifndef __PERSON_H
#define __PERSON_H

#include <fstream>
#include "BaseFunc.h"
#include <string>
#include <vector>

using namespace std;
#pragma warning(disable: 4996)

class Person
{
protected:
	string name;

	Person(const string);
	Person(ifstream& in) { in >> *this; }
	Person(const Person&) = default;
	Person(Person&&) = default;
	virtual ~Person() = default;



	void setName(const string name);

public:
	const char* getName()				const { return name.c_str(); }


	virtual void toOS(std::ostream& os) const {}

	virtual void fromOs(std::istream& in) const {}



	friend std::ostream& operator<<(std::ostream& os, const Person& person)
	{
		if (typeid(os) == typeid(ofstream))
			os << person.name;
		else 
			os << "Name - " << person.name;
		
		person.toOS(os);

		return os;
	}

	friend std::istream& operator>>(std::istream& in, Person& person)
	{
		in >> person.name;
		person.fromOs(in);

		return in;
	}

};

#endif // !__PERSON_H