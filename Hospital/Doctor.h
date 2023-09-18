#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "Staff.h"


class Doctor : virtual public Staff
{
protected:
	string m_specialty;

public:
	Doctor() = default;
	Doctor(const string name, const string specialty);
	Doctor(ifstream& in) { in >> *this; }
	Doctor(const Doctor&) = delete;
	Doctor(Doctor&&) noexcept;
	virtual ~Doctor() = default;

	void setSpecialty(const string specialty) { this->m_specialty = specialty; }

	const char* getSpecialty()			const { return m_specialty.c_str(); }


	virtual void toOS(std::ostream& os) const override 
	{ 
		if (typeid(os) == typeid(ofstream))
			os << " " << m_specialty;
		else
			os << ", Specialty - " << m_specialty; 
	}

	virtual void fromOS(std::istream& in) override
	{
		char delimeter = in.get();
		char strInput[M_MAX_NAME_LENGTH];
		in.getline(strInput, M_MAX_NAME_LENGTH);
		m_specialty = strInput;
	}

	
};


#endif //__DOCTOR_H