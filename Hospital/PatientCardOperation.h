#ifndef __PATIENT_CARD_OPERATION_H
#define __PATIENT_CARD_OPERATION_H


#include "Surgeon.h"
#include "PatientCard.h"

class PatientCardOperation : public PatientCard
{
protected:
	unsigned int room_number;
	bool fasting;

public:
	PatientCardOperation(Date date, const char* purpose_of_visit, Surgeon& doctor, unsigned int room_number, bool fasting);
	virtual ~PatientCardOperation();


	unsigned int getRoom_Number()		const { return room_number; }
	bool isFasting()					const { return fasting; }
 
	virtual void toOS(std::ostream& os) const 
	{
		os << "Operation Visit" << endl
			<< "Room number - " << room_number << ", Fasting - " << fasting << endl;
	}

};

#endif // !__PATIENT_CARD_OPERATION_H

