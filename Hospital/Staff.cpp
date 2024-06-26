
#include "Staff.h"

//--------------------------------------------------------------------------------//
//starting id is 1000 so it wont start with a 0000//
unsigned int Staff::counter = 1000;


//--------------------------------------------------------------------------------//
Staff::Staff(const string name) noexcept(false)
	:Person(name), workerId(counter)
{
	counter++;
}


//--------------------------------------------------------------------------------//
Staff::Staff(Staff&& other) noexcept :Person(other.getName()), workerId(other.getWorkerID())
{
	counter++; //rvalue staff will decrement counter upon destruction, so we wish to increment it now
}


//--------------------------------------------------------------------------------//
Staff& Staff::operator=(Staff&& other) noexcept
{
	std::swap(name, other.name);
	workerId = other.getWorkerID();
	counter++; //rvalue staff will decrement counter upon destruction, so we wish to increment it now
	return *this;
}

//--------------------------------------------------------------------------------//
Staff::~Staff()
{
	counter--;
}