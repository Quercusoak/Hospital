#include "Nurse.h"

//---------------------------------------------------------------//
Nurse::Nurse(const char* name, float yrs_of_experience)
	: name(nullptr), Staff(name)
{
	this->setExperience(yrs_of_experience);
}

//---------------------------------------------------------------//
void Nurse::setExperience(float experience)
{
	this->yrs_of_experience = experience;
}

//---------------------------------------------------------------//
Nurse::~Nurse()
{
	delete[]name;
}


//---------------------------------------------------------------//
float  Nurse::getExperience()
{
	return this->yrs_of_experience;
}
