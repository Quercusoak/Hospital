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
	PatientCardOperation(Date date, const string purpose_of_visit, Surgeon& doctor, unsigned int room_number, bool fasting) noexcept(false);
	PatientCardOperation(const PatientCardOperation&) = default;
	PatientCardOperation(PatientCardOperation&&) = default;
	virtual ~PatientCardOperation() = default;

	PatientCardOperation& operator=(PatientCardOperation&& other) noexcept = default;


	unsigned int getRoom_Number()		const { return room_number; }
	bool isFasting()					const { return fasting; }
 
	virtual void toOS(std::ostream& os) const
	{

		os << "		---Operation Visit---" << endl
			<< "Room number - " << room_number << ", Fasting - ";
		if (fasting)
			os << "True" << endl;
		else
			os << "False" << endl;

	}

	
};

#endif // !__PATIENT_CARD_OPERATION_H

