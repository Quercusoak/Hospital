
#include "Staff.h"

//--------------------------------------------------------------------------------//
//starting id is 1000 so it wont start with a 0000//
unsigned int Staff::counter = 1000;
//--------------------------------------------------------------------------------//
Staff::Staff(const char* name)
	:Person(name), workerId(counter)
{
	counter++;
}

//--------------------------------------------------------------------------------//
Staff::Staff(const Staff& other) :Person(other.getName()), workerId(counter)
{
	//counter++; if its being coppied, mb we dont want it to counter as a new person
	//move probably will work better
}

//--------------------------------------------------------------------------------//
Staff::~Staff()
{
	counter--;
}