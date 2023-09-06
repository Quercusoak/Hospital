#ifndef __PATIENTCARD_H
#define __PATIENTCARD_H

#include "Date.h"
#include "Doctor.h"


class PatientCard
{
protected:
	Date m_date;
	char* m_purpose_of_visit;
	Doctor* m_doctor;

public:
	PatientCard(Date date, const char* purpose_of_visit, Doctor& doctor);
	PatientCard(const PatientCard&);
	PatientCard(PatientCard&&);
	virtual ~PatientCard();


	void setPurpose(const char* purpose);
	
	Date getDate()					const { return m_date; }
	const char* getPurpose()		const { return m_purpose_of_visit; }
	Doctor& getDoctor()				const { return *m_doctor; }


	const PatientCard& operator=(const PatientCard&);
	const PatientCard& operator=(PatientCard&&);

};



#endif