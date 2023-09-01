#ifndef __SURGEON_H
#define __SURGEON_H

#include "Doctor.h"

class Surgeon : virtual public Doctor
{
protected:
	int num_surgeries;

public:
	Surgeon(const char* name, const char* specialty);
	Surgeon(Doctor&&);
	virtual ~Surgeon() {};

	//each time surgeon performs surgery add to counter
	void operator++();

	const int getNumSurgeriesPerformed() { return num_surgeries; }

	virtual void toOS(std::ostream& os) const override
	{
		os << ", Specialty - " << m_specialty << ", Number of Surgeries Performed: " << num_surgeries;
	}
};

#endif