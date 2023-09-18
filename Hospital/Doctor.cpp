
#include "Doctor.h"

//---------------------------------------------------------------//
Doctor::Doctor(const string name, const string specialty)
	: Staff(name)

{
	setSpecialty(specialty);
}

//---------------------------------------------------------------//
Doctor::Doctor(Doctor&& other) noexcept :Staff(std::move(other))
{
	std::swap(m_specialty, other.m_specialty);
}
