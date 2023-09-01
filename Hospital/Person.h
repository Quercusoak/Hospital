#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)


class Person
{
protected:
	char* name;

	Person(const char*);
	Person(const Person&);
	Person(Person&&);

	virtual ~Person();

	const Person& operator=(const Person&);
	const Person& operator=(Person&&);

	void setName(const char* name);

public:
	const char* getName()				const { return name; }

	virtual void toOS(std::ostream& os) const {}

	friend std::ostream& operator<<(std::ostream& os, const Person& person)
	{
		os << "Name - " << person.name;
		person.toOS(os);
		return os;
	}

};

#endif // !__PERSON_H