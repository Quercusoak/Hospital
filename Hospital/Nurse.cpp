#include "Nurse.h"

//---------------------------------------------------------------//
Nurse::Nurse(const string name, float yrs_of_experience) noexcept(false)
	: Staff(name)
{
	if (yrs_of_experience < 0)
		throw string("Nurse's years of experience cannot be negative value. Retry:");

	this->yrs_of_experience = yrs_of_experience;
}

//---------------------------------------------------------------//
Nurse::Nurse(Nurse&& other) noexcept :Staff(std::move(other))
{
	yrs_of_experience = other.getExperience();
}

//---------------------------------------------------------------//
void Nurse::setExperience(float experience)
{
	this->yrs_of_experience = experience;
}


//---------------------------------------------------------------//
float  Nurse::getExperience()
{
	return this->yrs_of_experience;
}
