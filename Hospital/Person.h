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
	char* getName()				const { return name; }

	
};

#endif // !__PERSON_H

