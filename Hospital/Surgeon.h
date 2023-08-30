#ifndef __SURGEON_H
#define __SURGEON_H

#include "Doctor.h"

class Surgeon : virtual protected Doctor
{
protected:
	int num_surgeries;

public:
	Surgeon(const char* name, const char* specialty);
	virtual ~Surgeon() {};

	//each time surgeon performs surgery add to counter
	void operator++();

	const int getNumSurgeriesPerformed() { return num_surgeries; }

};

#endif