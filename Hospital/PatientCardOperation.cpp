#include "PatientCardOperation.h"


//---------------------------------------------------------------//
PatientCardOperation::PatientCardOperation(PatientCard& card, unsigned int room_number, bool fasting)
	: PatientCard(std::move(card)), room_number(room_number), fasting(fasting)
{
}

//---------------------------------------------------------------//
PatientCardOperation::PatientCardOperation(Date date, const char* purpose_of_visit, 
	Doctor& doctor, unsigned int room_number, bool fasting)
	:PatientCard(date, purpose_of_visit, doctor), room_number(room_number), fasting(fasting)
{

}

//---------------------------------------------------------------//
PatientCardOperation::~PatientCardOperation()
{
}

//---------------------------------------------------------------//
