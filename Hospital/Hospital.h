#include "Ward.h"
#include "ResearchCenter.h"


class Hospital
{
private:
	Ward** wards;
	unsigned int num_wards;
	unsigned int max_wards;

	ResearchCenter research_center;

	vector<Patient> patients;


public:
	Hospital();
	Hospital(Hospital&) = delete;
	Hospital(Hospital&&) = delete;
	~Hospital();

	void AddWard(const char* ward_name);
	const unsigned int getWardsNum()	const { return num_wards; }
	Ward** getWards()					const { return wards; }


	Patient* searchPatientByID(unsigned int& id);
	Patient* addPatient(const string name, unsigned int id, Date birth_date, int gender);
	
	ResearchCenter& getResearchCenter() { return research_center; }

	void checkMaxSizeReached();

};