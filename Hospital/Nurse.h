#ifndef __NURSE_H
#define __NURSE_H

#include "Staff.h"

class Nurse : public Staff
{
private:
	float yrs_of_experience = 0; 
public:
	Nurse() = default;
	Nurse(const string name, float yrs_of_experience)noexcept(false);
	Nurse(ifstream& in) { in >> *this; }
	Nurse(const Nurse&) = delete;
	Nurse(Nurse&&) noexcept;
	virtual ~Nurse() = default;

	void setExperience(float);

	float getExperience();

	virtual void toOS(std::ostream& os) const override 
	{
		if (typeid(os) == typeid(ofstream))
			os << " " << yrs_of_experience;
		else
			os << ", Experience - " << yrs_of_experience << " Years.";
	}

	virtual void fromOS(std::istream& in) override
	{
		in >> yrs_of_experience;
		in.get();
	}

	

};

#endif __NURSE_H