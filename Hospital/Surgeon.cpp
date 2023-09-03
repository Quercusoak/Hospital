#include "Surgeon.h"

//---------------------------------------------------------------//
Surgeon::Surgeon(const char* name, const char* specialty)
	:Doctor(name, specialty), Staff(name)
{
	cout << "Surgeon c'tor	" << this->workerId << endl; //to del

	num_surgeries = 0;
}


//---------------------------------------------------------------//
Surgeon::Surgeon(Doctor&& other) :Doctor(std::move(other)),Staff(std::move(other))
{
	cout << "Surgeon move c'tor	 "<< this->workerId << endl; //to del

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
	os << ", Job - Surgeon, Specialty - " << m_specialty << ", Number of Surgeries Performed: " << num_surgeries;
}