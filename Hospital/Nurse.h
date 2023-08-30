#ifndef __NURSE_H
#define __NURSE_H

#include "Staff.h"
//added to branch
class Nurse : public Staff
{
private:
	float yrs_of_experience;
	
public:
	Nurse(const char* name, float yrs_of_experience);
	Nurse(Nurse&) = delete;
	Nurse(Nurse&&) = delete;
	virtual ~Nurse();

	void setExperience(float);

	float getExperience();

	virtual void toOS(std::ostream& os) const override { os << ", Job - Nurse, Experience - " << yrs_of_experience << " Years."; }

	friend std::ostream& operator<<(std::ostream& os, const Nurse& nurse)
	{
		os << "Name - " << nurse.name << ", worker Id - " << nurse.workerId << ", Job - Nurse, Experience - " 
			<< nurse.yrs_of_experience << " Years.";
		return os;
	}

};

#endif __NURSE_H