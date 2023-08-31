#include "Surgeon.h"

//---------------------------------------------------------------//
Surgeon::Surgeon(const char* name, const char* specialty)
	:Doctor(name, specialty), Staff(name)
{
	num_surgeries = 0;
}


//---------------------------------------------------------------//
Surgeon::Surgeon(Doctor&& other) :Doctor(other),Staff(other.getName())
{
	num_surgeries = 0;
}

//---------------------------------------------------------------//
void Surgeon::operator++()
{
	num_surgeries++;
}