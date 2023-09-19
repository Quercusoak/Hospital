#include "Patient.h"

//---------------------------------------------------------------//
Patient::Patient(const string name, unsigned int id, Date date, unsigned int gender) noexcept(false)
	:Person(name)
{	
	if (id < 1)
		throw string("ID invalid.");

	if (gender != 0 && gender != 1)
		throw string("Gender must be one of the binary options.");

	setID(id);
	setGender((Patient::eGender)gender);
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
void Patient::AddVisit(Date date, const string purpose_of_visit, Doctor& doctor)
{
	checkCapacity();
	try
	{
	patient_card.push_back(new PatientCard(date, purpose_of_visit, doctor));
	}
	catch (string& e)
	{
		cout << e << endl;
	}
}

//---------------------------------------------------------------//
void Patient::AddVisit(Date date, const string purpose_of_visit, Surgeon& surgeon, int roomNumber, bool fasting)
{
	checkCapacity();
	try
	{
	patient_card.push_back(new PatientCardOperation(date, purpose_of_visit, surgeon, roomNumber, fasting));
	}
	catch (string& e)
	{
		cout << e << endl;
	}
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