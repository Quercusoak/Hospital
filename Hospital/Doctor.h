#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "Staff.h"


class Doctor : virtual public Staff
{
protected:
	string m_specialty;

public:
	Doctor(const string name, const string specialty);
	Doctor(const Doctor&) = delete;
	Doctor(Doctor&&) noexcept;
	virtual ~Doctor() = default;

	void setSpecialty(const string specialty) { this->m_specialty = specialty; }

	const char* getSpecialty()			const { return m_specialty.c_str(); }


	virtual void toOS(std::ostream& os) const override { os << ", Specialty - " << m_specialty; }


	/*
	friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor)
	{
		os << "Name - " << doctor.name << ", worker id - " << doctor.workerId << ", Job - Doctor, Specialty - "
			<< doctor.m_specialty << ".";
		return os;
	}
	*/
};


#endif //__DOCTOR_H