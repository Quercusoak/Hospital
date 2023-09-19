#include "Ward.h"
#include "ResearchCenter.h"
#include "TemplateArray.h"

class Hospital
{
private:

	TemplateArray<Ward> wards;

	ResearchCenter research_center;

	vector<Patient> patients;


public:
	Hospital();
	Hospital(Hospital&) = delete;
	Hospital(Hospital&&) = delete;
	~Hospital();

	void AddWard(const string ward_name) noexcept(false);
	const unsigned int getWardsNum()			const { return wards.size(); }
	TemplateArray<Ward>& getWards()				 { return wards; }


	Patient* searchPatientByID(unsigned int& id);
	Patient* addPatient(const string name, unsigned int id, Date birth_date, int gender);
	
	ResearchCenter& getResearchCenter() { return research_center; }

};