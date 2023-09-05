
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
Staff::Staff(Staff&& other) :Person(other.getName()), workerId(other.getWorkerID())
{
	other.name = nullptr;
	counter++; //rvalue staff will decrement counter upon destruction, so we wish to increment it now
}

//--------------------------------------------------------------------------------//
Staff::~Staff()
{
	counter--;
}