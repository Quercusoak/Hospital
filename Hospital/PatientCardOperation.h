#ifndef __PATIENT_CARD_OPERATION_H
#define __PATIENT_CARD_OPERATION_H




#include "PatientCard.h"

class PatientCardOperation : public PatientCard
{
protected:
	unsigned int room_number;
	bool fasting;

public:
	PatientCardOperation(PatientCard& card, unsigned int room_number, bool fasting);
	virtual ~PatientCardOperation();

};

#endif // !__PATIENT_CARD_OPERATION_H

