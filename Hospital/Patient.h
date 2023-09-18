#ifndef __PATIENT_H
#define __PATIENT_H

#include "PatientCardOperation.h"
#include "Person.h"

#define OPRATION 1
#define NORMAL 0

class Patient : public Person
{
public:
	enum class eGender { male, female };
	static constexpr const char* genderStr[] = { "male", "female" };

private:
	unsigned int id;
	Date date;
	eGender gender;

	vector<PatientCard*> patient_card;


public:
	Patient(const string name, unsigned int id, Date date, eGender);
	Patient(Patient&) = delete;
	Patient(Patient&&) noexcept;
	Patient& operator=(Patient&& other) noexcept;
	virtual ~Patient();

	void setID(unsigned int id);
	void setGender(eGender);
	void setDate(Date);

	unsigned int getID()				const { return id; }
	const char* getGender()				const { return genderStr[(int)gender]; }
	const unsigned int getNumVisits()	const { return patient_card.size(); }

	vector<PatientCard*>& getPatientCard()			  { return patient_card; }

	void AddVisit(Date date, const char* purpose_of_visit, Doctor& doctor);
	void AddVisit(Date date, const char* purpose_of_visit, Surgeon& surgeon, int roomNumber, bool fasting);

	void checkCapacity();

	virtual void toOS(std::ostream& os) const override
	{
		os << ", Gender - " << getGender() << ", Id - " << id
			<< ", Number of visits - " << patient_card.size();
	}





};


#endif