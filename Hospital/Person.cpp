#include "Person.h"


//---------------------------------------------------------------//
void Person::setName(const string name) noexcept(false)
{
	if (name == "")
		throw string("A person must have a name - cannot accept empty string.");

  this->name = name;
}

//---------------------------------------------------------------//
Person::Person(const string name) noexcept(false)
{
	setName(name);
}
