#include "Ward.h"
#include "ResearchCenter.h"
#include "Patient.h"
#include "BaseFunc.h"

class Hospital
{
private:
	Ward** wards;
	unsigned int num_wards;
	unsigned int max_wards;

	Nurse** nurses;
	unsigned int num_nurses;
	unsigned int max_nurse_size;

	Doctor** doctors;
	unsigned int num_doctors;
	unsigned int max_doctors_size;

	ResearchCenter research_center;

	Patient** patients;
	unsigned int num_patients;
	unsigned int max_patients;

public:
	Hospital();
	Hospital(Hospital&) = delete;
	Hospital(Hospital&&) = delete;
	~Hospital();

	void AddWard(const char* ward_name);
	const unsigned int getWardsNum()	const { return num_wards; }
	Ward** getWards()					const { return wards; }


	void AddNurse(const char* name, float yrs_of_experience, Ward& ward);
	const unsigned int getNumNurses()	const { return num_nurses; }
	Nurse* const* getNurses()					const { return nurses; }
	

	void AddDoctor(const char* name, const char* specialty, Ward& ward);
	const unsigned int getNumDoctors()	const { return num_doctors; }
	Doctor* const* getDoctors()				const { return doctors; }


	Patient* searchPatientByID(unsigned int& id);
	Patient* addPatient(const char* name, unsigned int id, Date birth_date, int gender);

	
	ResearchCenter& getResearchCenter() { return research_center; }

	//Returns true if there are no matching id in system
	bool searchWorkerId(unsigned int) const;

};