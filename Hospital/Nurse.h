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
};

#endif __NURSE_H