#ifndef __NURSE_H
#define __NURSE_H

#include "Staff.h"

class Nurse : public Staff
{
private:
	float yrs_of_experience;

public:
	Nurse(const string name, float yrs_of_experience);
	Nurse(Nurse&) = delete;
	Nurse(Nurse&&);
	virtual ~Nurse() = default;

	void setExperience(float);

	float getExperience();

	virtual void toOS(std::ostream& os) const override { os << ", Experience - " << yrs_of_experience << " Years."; }

	

};

#endif __NURSE_H