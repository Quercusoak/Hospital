
#include "Doctor.h"

//---------------------------------------------------------------//
void Doctor::setSpecialty(const string specialty)
{
	m_specialty = specialty;
}

//---------------------------------------------------------------//
Doctor::Doctor(const string name, const string specialty)
	: Staff(name), m_specialty(specialty)
{
	setSpecialty(specialty);
}


//---------------------------------------------------------------//
Doctor::Doctor(Doctor&& other) :Staff(std::move(other))
{
	setSpecialty(other.getSpecialty());
}
