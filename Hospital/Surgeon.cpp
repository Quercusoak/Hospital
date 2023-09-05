#include "Surgeon.h"

//---------------------------------------------------------------//
Surgeon::Surgeon(const char* name, const char* specialty)
	:Doctor(name, specialty), Staff(name)
{
	num_surgeries = 0;
}


//---------------------------------------------------------------//
Surgeon::Surgeon(Doctor&& other) :Doctor(std::move(other)),Staff(std::move(other))
{
	num_surgeries = 0;
}

//---------------------------------------------------------------//
void Surgeon::operator++()
{
	num_surgeries++;
}

// --------------------------------------------------------------------------------//
void Surgeon::toOS(std::ostream& os) const
{
	Doctor::toOS(os);
	os << ", Number of Surgeries Performed: " << num_surgeries;
}