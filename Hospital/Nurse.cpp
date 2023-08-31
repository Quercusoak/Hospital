#include "Nurse.h"

//---------------------------------------------------------------//
Nurse::Nurse(const char* name, float yrs_of_experience)
	: Staff(name), yrs_of_experience(yrs_of_experience)
{
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
