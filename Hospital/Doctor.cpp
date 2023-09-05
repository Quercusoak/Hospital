
#include "Doctor.h"

//---------------------------------------------------------------//
void Doctor::setSpecialty(const char* specialty) 
{
	delete[]m_specialty;
	m_specialty = new char[strlen(specialty) + 1];
	strcpy(m_specialty, specialty);
}

//---------------------------------------------------------------//
Doctor::Doctor(const char* name, const char* specialty)
	: Staff(name), m_specialty(nullptr)
{
	setSpecialty(specialty);
}


//---------------------------------------------------------------//
Doctor::Doctor(Doctor&& other) :Staff(std::move(other))
{
	setSpecialty(other.getSpecialty());
	other.m_specialty = nullptr;
}

//---------------------------------------------------------------//
Doctor::~Doctor()
{
	delete[]m_specialty;
}