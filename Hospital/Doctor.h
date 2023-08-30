#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "Staff.h"

class Doctor : virtual public Staff
{
protected:
	char* m_specialty;

public:
	Doctor(const char* name, const char* specialty);
	Doctor(const Doctor&) = delete;
	Doctor(Doctor&&) = delete;
	virtual ~Doctor();

	void setSpecialty(const char* specialty);

	char* getSpecialty()		const { return m_specialty; }

};


#endif //__DOCTOR_H