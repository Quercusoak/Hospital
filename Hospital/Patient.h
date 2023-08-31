#ifndef __PATIENT_H
#define __PATIENT_H

#include "PatientCard.h"
#include "Person.h"


class Patient : public Person
{
public:
	enum class eGender { male, female };
	static constexpr const char* genderStr[] = { "male", "female" };

private:
	unsigned int id;
	Date date;
	eGender gender;
	PatientCard** patient_card;
	unsigned int num_visits;
	unsigned int max_visits;


public:
	Patient(const char* name, unsigned int id, Date date, eGender);
	Patient(Patient&) = delete;
	Patient(Patient&&) = delete;
	virtual ~Patient();

	void setID(unsigned int id);
	void setGender(eGender);
	void setDate(Date);

	unsigned int getID()				const { return id; }
	const char* getGender()				const { return genderStr[(int)gender]; }
	const unsigned int getNumVisits()	const { return num_visits; }

	PatientCard** getPatientCard()			  { return patient_card; }

	void AddVisit(Date date, const char* purpose_of_visit, Doctor& doctor);


	virtual void toOS(std::ostream& os) const override 
  {
		os << ", Gender - " << getGender() << ", Id - " << id
			<< ", Number of visits - " << num_visits;
	}


	friend std::ostream& operator<<(std::ostream& os, const Patient& patient)
	{
		os << "Name - " << patient.name << ", Paitant, Gender - " << patient.getGender() << ", Id - " << patient.id
			<< ", Number of visits - " << patient.num_visits;;

		return os;
	}
};


#endif