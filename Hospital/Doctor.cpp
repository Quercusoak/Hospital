
#include "Doctor.h"

//---------------------------------------------------------------//
Doctor::Doctor(const string name, const string specialty) noexcept(false)
	: Staff(name)
{
	if (specialty == "")
		throw string("Doctor's erea of specialty cannot be empty.");

	m_specialty = specialty;
}

//---------------------------------------------------------------//
Doctor::Doctor(Doctor&& other) noexcept :Staff(std::move(other))
{
	std::swap(m_specialty, other.m_specialty);
}
