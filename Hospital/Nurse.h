#ifndef __NURSE_H
#define __NURSE_H

#include "Staff.h"

class Nurse : public Staff
{
private:
	float yrs_of_experience;

public:
	Nurse(const char* name, float yrs_of_experience);
	Nurse(Nurse&) = delete;
	Nurse(Nurse&&);
	virtual ~Nurse();

	void setExperience(float);

	float getExperience();

	virtual void toOS(std::ostream& os) const override { os << ", Experience - " << yrs_of_experience << " Years."; }

	friend std::ostream& operator<<(std::ostream& os, const Nurse& nurse)
	{
		os << "Name - " << nurse.name << ", worker id - " << nurse.workerId << ", Job - Nurse, Experience - "
			<< nurse.yrs_of_experience << " years.";
		return os;
	}

};

#endif __NURSE_H