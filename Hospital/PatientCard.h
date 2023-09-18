#ifndef __PATIENTCARD_H
#define __PATIENTCARD_H

#include "Date.h"
#include "Doctor.h"


class PatientCard
{
protected:
	Date m_date;
	string m_purpose_of_visit;
	Doctor* m_doctor;

public:
	PatientCard(Date date, const string purpose_of_visit, Doctor& doctor);
	PatientCard(const PatientCard&) = default;
	PatientCard(PatientCard&&) = default;
	virtual ~PatientCard() = default;

	PatientCard& operator=(PatientCard&& other) noexcept = default;

	void setPurpose(const string purpose)	{ this->m_purpose_of_visit = purpose; }

	
	Date getDate()					const { return m_date; }
	const char* getPurpose()		const { return m_purpose_of_visit.c_str(); }
	Doctor& getDoctor()				const { return *m_doctor; }




	virtual void toOS(std::ostream& os) const {}

	friend std::ostream& operator<<(std::ostream& os, const PatientCard& patientCard)
	{
		os << "-------------------------------------------------------------" << endl
			<< "Date - " << patientCard.m_date << endl
			<< "Doctor visited - " << patientCard.getDoctor().getName() << endl
			<< "Reason for visit - " << patientCard.m_purpose_of_visit << endl;
		patientCard.toOS(os);
		os << "-------------------------------------------------------------";
		return os;
	}
};



#endif