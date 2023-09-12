#include "Nurse.h"

//---------------------------------------------------------------//
Nurse::Nurse(const string name, float yrs_of_experience)
	: Staff(name), yrs_of_experience(yrs_of_experience)
{
}

//---------------------------------------------------------------//
Nurse::Nurse(Nurse&& other) :Staff(std::move(other))
{
	yrs_of_experience = other.getExperience();
}

//---------------------------------------------------------------//
void Nurse::setExperience(float experience)
{
	this->yrs_of_experience = experience;
}

//---------------------------------------------------------------//
Nurse::~Nurse()
{
}


//---------------------------------------------------------------//
float  Nurse::getExperience()
{
	return this->yrs_of_experience;
}
