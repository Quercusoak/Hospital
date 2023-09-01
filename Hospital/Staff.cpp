
#include "Staff.h"

//--------------------------------------------------------------------------------//
//starting id is 1000 so it wont start with a 0000//
unsigned int Staff::counter = 1000;
//--------------------------------------------------------------------------------//
Staff::Staff(const char* name)
	:Person(name), workerId(counter)
{
	cout << "Staff c'tor	" << this->workerId << endl; //to del

	counter++;
}

//--------------------------------------------------------------------------------//
Staff::Staff(const Staff& other) :Person(other.getName()), workerId(counter)
{
	//counter++; if its being coppied, mb we dont want it to counter as a new person
	//move probably will work better
}

//--------------------------------------------------------------------------------//
Staff::Staff(Staff&& other) :Person(other.getName()), workerId(other.getWorkerID())
{
	cout << "Staff move c'tor	" << this->workerId << endl; //to del
	other.name = nullptr;
}

//--------------------------------------------------------------------------------//
Staff::~Staff()
{
	counter--;
}