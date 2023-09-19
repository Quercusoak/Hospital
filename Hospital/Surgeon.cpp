#include "Surgeon.h"

//---------------------------------------------------------------//
Surgeon::Surgeon(const string name, const string specialty)
	:Doctor(name, specialty), Staff(name)
{
	num_surgeries = 0;
}


//---------------------------------------------------------------//
Surgeon::Surgeon(Doctor&& other) :Doctor(std::move(other)),Staff(std::move(other))
{
	Surgeon* surgeon = dynamic_cast<Surgeon*>(&other);
	if (surgeon)
		num_surgeries = surgeon->num_surgeries;
	else
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
	if (typeid(os) == typeid(ofstream))
		os << endl << num_surgeries;
	else
		os << ", Number of Surgeries Performed: " << num_surgeries;
}

// --------------------------------------------------------------------------------//
void Surgeon::fromOS(std::istream& in)
{
	Doctor::fromOS(in);
	in >> num_surgeries;
	in.get();

}