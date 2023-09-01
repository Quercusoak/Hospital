#include "PatientCard.h"


//---------------------------------------------------------------//
void PatientCard::setPurpose(const char* purpose)
{
	delete[]m_purpose_of_visit;
	m_purpose_of_visit = new char[strlen(purpose) + 1];
	strcpy(m_purpose_of_visit, purpose);

}

//---------------------------------------------------------------//
PatientCard::PatientCard(Date date, const char* purpose_of_visit, Doctor& doctor)
	: m_date(date.getYear(), date.getMonth(), date.getDay()), m_purpose_of_visit(nullptr)
{
	setPurpose(purpose_of_visit);
	this->m_doctor = &doctor;
}

//---------------------------------------------------------------//
PatientCard::PatientCard(const PatientCard& other)
	: m_purpose_of_visit(nullptr)
{
	*this = other;
}

//---------------------------------------------------------------//
PatientCard::PatientCard(PatientCard&& other)
	: m_purpose_of_visit(nullptr)
{
	*this = std::move(other);
}

//---------------------------------------------------------------//
PatientCard::~PatientCard()
{
	delete[]m_purpose_of_visit;
	
}

//---------------------------------------------------------------//
const PatientCard& PatientCard::operator=(const PatientCard& other)
{
	if (this != &other) {
		this->m_date = other.m_date;
		setPurpose(other.m_purpose_of_visit);
		this->m_doctor = other.m_doctor;
	}
	return *this;
}

//---------------------------------------------------------------//
const PatientCard& PatientCard::operator=(PatientCard&& other)
{
	if (this != &other) {
		this->m_date = other.m_date;
		std::swap(other.m_purpose_of_visit, this->m_purpose_of_visit);
		this->m_doctor = other.m_doctor;
	}
	return *this;
}