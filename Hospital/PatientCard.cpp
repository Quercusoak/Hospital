#include "PatientCard.h"


//---------------------------------------------------------------//
void PatientCard::setPurpose(const char* purpose)
{
	delete[]m_purpose_of_visit;
	m_purpose_of_visit = new char[strlen(purpose) + 1];
	strcpy(m_purpose_of_visit, purpose);

}

//---------------------------------------------------------------//
PatientCard::PatientCard(Date date, const char* purpose_of_visit, Doctor& doctor): m_date(date.getYear(),date.getMonth(),date.getDay())
{
	setPurpose(purpose_of_visit);
	this->m_doctor = &doctor;
}

//---------------------------------------------------------------//
PatientCard::~PatientCard()
{
	delete[]m_purpose_of_visit;
	
}
