#include "PatientCardOperation.h"




//---------------------------------------------------------------//
PatientCardOperation::PatientCardOperation(Date date, const char* purpose_of_visit, 
	Surgeon& doctor, unsigned int room_number, bool fasting)
	:PatientCard(date, purpose_of_visit, doctor), room_number(room_number), fasting(fasting)
{
	doctor.addSurgery();
}

//---------------------------------------------------------------//
PatientCardOperation::~PatientCardOperation()
{
}

//---------------------------------------------------------------//
