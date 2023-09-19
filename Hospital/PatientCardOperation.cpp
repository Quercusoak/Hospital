#include "PatientCardOperation.h"

//---------------------------------------------------------------//
PatientCardOperation::PatientCardOperation(Date date, const string purpose_of_visit, 
	Surgeon& doctor, unsigned int room_number, bool fasting) noexcept(false)
	:PatientCard(date, purpose_of_visit, doctor), room_number(room_number), fasting(fasting)
{
	if (room_number < 0)
		throw string("Room number cannot be negative value.");

	if (fasting != 0 && fasting != 1)
		throw string("Fasting must be one of the binary options.");

	doctor.addSurgery();
}
