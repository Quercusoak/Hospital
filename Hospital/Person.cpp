#include "Person.h"


//---------------------------------------------------------------//
void Person::setName(const string name)
{
  this->name = name;
}

//---------------------------------------------------------------//
Person::Person(const string name)
{
	setName(name);
}
