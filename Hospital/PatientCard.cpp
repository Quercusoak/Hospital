#include "PatientCard.h"

//---------------------------------------------------------------//
PatientCard::PatientCard(Date date, const string purpose_of_visit, Doctor& doctor) noexcept(false)
	: m_date(date.getYear(), date.getMonth(), date.getDay())
{
	if (purpose_of_visit == "")
		throw string("Must provide purpose for hospital visit.");

	setPurpose(purpose_of_visit);
	this->m_doctor = &doctor;
	this->doctorId = doctor.getWorkerID();
}
