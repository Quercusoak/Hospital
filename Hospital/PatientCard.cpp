#include "PatientCard.h"

//---------------------------------------------------------------//
PatientCard::PatientCard(Date date, const string purpose_of_visit, Doctor& doctor)
	: m_date(date.getYear(), date.getMonth(), date.getDay())
{
	setPurpose(purpose_of_visit);
	this->m_doctor = &doctor;
}

////---------------------------------------------------------------//
//PatientCard::PatientCard(PatientCard&& other) noexcept
//{
//	m_doctor = &other.getDoctor();
//
//}

