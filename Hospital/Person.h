#ifndef __PERSON_H
#define __PERSON_H

#include "BaseFunc.h"
#include "Exceptions.h"
#include <vector>
#include <fstream>


class Person
{
protected:
	string name;
	static const int M_MAX_NAME_LENGTH = 128;
	Person() = default;
	Person(const string) noexcept(false);
	Person(ifstream& in) { in >> *this; }
	Person(const Person&) = default;
	Person(Person&&) = default;
	virtual ~Person() = default;



	void setName(const string name);

public:
	const char* getName()				const { return name.c_str(); }


	virtual void toOS(std::ostream& os) const {}

	virtual void fromOS(std::istream& in) {}



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
		char name[M_MAX_NAME_LENGTH];
		in.getline(name, M_MAX_NAME_LENGTH);
		person.name = name;

		person.fromOS(in);
		return in;
	}

};

#endif // !__PERSON_H