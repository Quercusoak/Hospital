#include "Ward.h"
#include "ResearchCenter.h"

class Hospital
{
private:
	Ward** wards;
	unsigned int num_wards;
	unsigned int max_wards;

	//Staff is array of pointers to the staff array in wards, each pointer - different ward
	Staff*** staff;

	ResearchCenter research_center;

	Patient** patients;
	unsigned int num_patients;
	unsigned int max_patients;

	unsigned int wards_doctors;
	unsigned int wards_researchers;
	unsigned int wards_nurses;

public:
	Hospital();
	Hospital(Hospital&) = delete;
	Hospital(Hospital&&) = delete;
	~Hospital();

	void AddWard(const char* ward_name);
	const unsigned int getWardsNum()	const { return num_wards; }
	Ward** getWards()					const { return wards; }


	Patient* searchPatientByID(unsigned int& id);
	Patient* addPatient(const char* name, unsigned int id, Date birth_date, int gender);
	
	ResearchCenter& getResearchCenter() { return research_center; }

	void checkMaxSizeReached();

};