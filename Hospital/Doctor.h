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

	friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor)
	{
		os << "Docotr " << doctor.getName() << ", worker ID: " << doctor.getWorkerID() << ", specialty: " << doctor.getSpecialty() << "." << endl;
		return os;
	}

};


#endif //__DOCTOR_H