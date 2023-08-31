
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
	//cout << "in Doctor::Doctor c'tor, debugging line " << name << endl;

	setSpecialty(specialty);
}

//---------------------------------------------------------------//
Doctor::~Doctor()
{
	//cout << "in Doctor::~Doctor d'tor, debugging line " << m_name << endl;

	delete[]m_specialty;

}