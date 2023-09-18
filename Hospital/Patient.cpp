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
Patient::Patient(Patient&& other) noexcept :Person(std::move(other))
{
	setID(other.getID());
	setGender(other.gender);
	setDate(other.date);

	for (auto& elem : other.patient_card)
	{
		patient_card.push_back(elem);
	}
	other.patient_card.clear();
}


//---------------------------------------------------------------//
Patient& Patient::operator=(Patient&& other) noexcept 
{
	std::swap(name, other.name);
	setID(other.getID());
	setGender(other.gender);
	setDate(other.date);
	
	for (auto& elem : other.patient_card)
	{
		patient_card.push_back(elem);
	}
	other.patient_card.clear();

	return *this;
}


//---------------------------------------------------------------//
void Patient::AddVisit(Date date, const char* purpose_of_visit, Doctor& doctor)
{
	checkCapacity();
	patient_card.push_back(new PatientCard(date, purpose_of_visit, doctor));
}

//---------------------------------------------------------------//
void Patient::AddVisit(Date date, const char* purpose_of_visit, Surgeon& surgeon, int roomNumber, bool fasting)
{
	checkCapacity();
	patient_card.push_back(new PatientCardOperation(date, purpose_of_visit, surgeon, roomNumber, fasting));
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
	vector<PatientCard*>::iterator itr = patient_card.begin();
	for (auto& elem : patient_card)
	{
		if (itr != patient_card.end())
			itr = patient_card.erase(itr);
		else
			patient_card.erase(itr);
	}
	patient_card.clear();

}