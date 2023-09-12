#include "Patient.h"

//---------------------------------------------------------------//
Patient::Patient(const string name, unsigned int id, Date date, eGender gender)
	:Person(name)
{
	setID(id);
	setGender(gender);
	setDate(date);
}

//---------------------------------------------------------------//
Patient::Patient(Patient&& other) :Person(std::move(other))
{

	setID(other.getID());
	setGender(other.gender);
	setDate(other.date);
}

//---------------------------------------------------------------//
void Patient::AddVisit(Date date, const char* purpose_of_visit, Doctor& doctor)
{
	checkCapacity();
	patient_card.push_back(PatientCard(date, purpose_of_visit, doctor));
}

//---------------------------------------------------------------//
void Patient::AddVisit(Date date, const char* purpose_of_visit, Surgeon& surgeon, int roomNumber, bool fasting)
{
	checkCapacity();
	patient_card.push_back(PatientCardOperation(date, purpose_of_visit, surgeon, roomNumber, fasting));
}

//---------------------------------------------------------------//
void Patient::checkCapacity()
{
	if (patient_card.size() == patient_card.capacity())
		patient_card.reserve(patient_card.capacity() * 2);
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
	patient_card.clear();
}