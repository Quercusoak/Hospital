#ifndef __PATIENT_CARD_OPERATION_H
#define __PATIENT_CARD_OPERATION_H



#include "PatientCard.h"

class PatientCardOperation : public PatientCard
{
protected:
	unsigned int room_number;
	bool fasting;

public:
	PatientCardOperation(Date date, const char* purpose_of_visit, Doctor& doctor, unsigned int room_number, bool fasting);
	PatientCardOperation(PatientCard& card, unsigned int room_number, bool fasting);
	virtual ~PatientCardOperation();


	unsigned int getRoom_Number()		const { return room_number; }
	bool isFasting()					const { return fasting; }
 
};

#endif // !__PATIENT_CARD_OPERATION_H

