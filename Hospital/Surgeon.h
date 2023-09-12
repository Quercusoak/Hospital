#ifndef __SURGEON_H
#define __SURGEON_H

#include "Doctor.h"

class Surgeon : virtual public Doctor
{
protected:
	int num_surgeries;

public:
	Surgeon(const string name, const string specialty);
	Surgeon(Doctor&&);
	virtual ~Surgeon() {};

	//each time surgeon performs surgery add to counter
	void operator++();

	const int getNumSurgeriesPerformed() { return num_surgeries; }

	virtual void toOS(std::ostream& os) const override;
	
	virtual const string type() const override { return typeid(*this).name() + 6; }

	void addSurgery() { num_surgeries++; }
};

#endif