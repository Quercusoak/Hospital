#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "Staff.h"

class Doctor : virtual public Staff
{
protected:
	char* m_specialty;

public:
	Doctor(const char* name, const char* specialty);
	Doctor(const Doctor&);
	Doctor(Doctor&&);
	virtual ~Doctor();

	void setSpecialty(const char* specialty);

	char* getSpecialty()		const { return m_specialty; }


	virtual void toOS(std::ostream& os) const override { os << ", Job - Doctor, Specialty - " << m_specialty << "."; }

	friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor)
	{
		os << "Name - " << doctor.name << ", worker id - " << doctor.workerId << ", Job - Doctor, Specialty - "
			<< doctor.m_specialty << ".";
		return os;
	}

};


#endif //__DOCTOR_H