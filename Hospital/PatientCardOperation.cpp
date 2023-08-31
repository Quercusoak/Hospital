#include "PatientCardOperation.h"


//---------------------------------------------------------------//
PatientCardOperation::PatientCardOperation(PatientCard& card, unsigned int room_number, bool fasting)
	: PatientCard(std::move(card)), room_number(room_number), fasting(fasting)
{
}

//---------------------------------------------------------------//
PatientCardOperation::~PatientCardOperation()
{
}

//---------------------------------------------------------------//
