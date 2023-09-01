#include "Person.h"


//---------------------------------------------------------------//
void Person::setName(const char* name)
{

	delete[](this->name);

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

}

//---------------------------------------------------------------//
Person::Person(const char* name)
	:name(nullptr)
{
	setName(name);

}

//---------------------------------------------------------------//
Person::Person(const Person& other)
	:name(nullptr)
{
	*this = other;
}

//---------------------------------------------------------------//
Person::Person(Person&& other)
	:name(nullptr)
{
	*this = std::move(other);
}

//---------------------------------------------------------------//
Person::~Person()
{
	delete[]name;

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