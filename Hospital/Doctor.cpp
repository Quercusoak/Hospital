
#include "Doctor.h"


//---------------------------------------------------------------//
Doctor::Doctor(const string name, const string specialty)
	: Staff(name)
{
	setSpecialty(specialty);
}

