#include "Patient.h"

//---------------------------------------------------------------//
Patient::Patient(const string name, unsigned int id, Date date, eGender gender)
	:Person(name)
{
	setID(id);
	setGender(gender);
	setDate(date);
	num_visits = 0;
	max_visits = 1;
	patient_card = new PatientCard * [max_visits];
	patient_card[0] = nullptr;
}

//---------------------------------------------------------------//
Patient::Patient(Patient&& other) noexcept :Person(std::move(other))
{
	setID(other.getID());
	setGender(other.gender);
	setDate(other.date);
	num_visits = other.num_visits;
	max_visits = other.max_visits;
	patient_card = other.patient_card;
	other.patient_card = nullptr;
}


//---------------------------------------------------------------//
Patient& Patient::operator=(Patient&& other) noexcept 
{
	std::swap(name, other.name);
	setID(other.getID());
	setGender(other.gender);
	setDate(other.date);
	num_visits = other.num_visits;
	max_visits = other.max_visits;
	patient_card = other.patient_card;
	other.patient_card = nullptr;
	return *this;
}


//---------------------------------------------------------------//
void Patient::AddVisit(Date date, const char* purpose_of_visit, Doctor& doctor)
{
	if (num_visits == max_visits)
	{
		max_visits *= 2;
		patient_card = (PatientCard**)rerealloc(patient_card, sizeof(PatientCard*), num_visits, max_visits);
	}

	patient_card[num_visits] = new PatientCard(date, purpose_of_visit, doctor);
	num_visits++;
}

//---------------------------------------------------------------//
void Patient::AddVisit(Date date, const char* purpose_of_visit, Surgeon& surgeon, int roomNumber, bool fasting)
{
	if (num_visits == max_visits)
	{
		max_visits *= 2;
		patient_card = (PatientCard**)rerealloc(patient_card, sizeof(PatientCard*), num_visits, max_visits);
	}

	patient_card[num_visits] = new PatientCardOperation(date, purpose_of_visit, surgeon, roomNumber, fasting);
	num_visits++;
}

//---------------------------------------------------------------//
void Patient::checkCapacity()
{
	if (num_visits == max_visits)
	{
		max_visits *= 2;
		patient_card = (PatientCard**)rerealloc(patient_card, sizeof(PatientCard*), num_visits, max_visits);
	}
}

//---------------------------------------------------------------//
void Patient::setID(unsigned int id)
{
	this->id = id;
}

//---------------------------------------------------------------//
void Patient::setGender(eGender gender)
{
	this->gender = gender;
}

//---------------------------------------------------------------//
void Patient::setDate(Date date)
{
	this->date = date;
}

//---------------------------------------------------------------//
Patient::~Patient()
{
	/*patient_card.clear();*/
	if (patient_card != nullptr)
	{
		for (unsigned int i = 0; i < num_visits; i++)
		{
			delete patient_card[i];
		}
		delete[] patient_card;
	}
}