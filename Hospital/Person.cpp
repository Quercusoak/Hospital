#include "Person.h"


//---------------------------------------------------------------//
void Person::setName(const string name)
{
	this->name = name;
}

//---------------------------------------------------------------//
Person::Person(const string name)
	:name(name)
{
	setName(name);
}

//---------------------------------------------------------------//
Person::Person(const Person& other)
	:name(name)
{
	*this = other;
}

//---------------------------------------------------------------//
Person::Person(Person&& other)
	:name(other.name)
{
	*this = std::move(other);
}


//---------------------------------------------------------------//
const Person& Person::operator=(const Person& other)
{
	if (this != &other) {
		this->setName(other.name);
	}

	return *this;
}

//---------------------------------------------------------------//
const Person& Person::operator=(Person&& other)
{
	if (this != &other) {
		std::swap(other.name, this->name);
	}
	return *this;
}