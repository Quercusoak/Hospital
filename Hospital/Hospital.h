#include "Ward.h"
#include "ResearchCenter.h"
#include "TemplateArray.h"
#include <algorithm>

class Hospital
{
private:

	TemplateArray<Ward> wards;

	ResearchCenter research_center;

	vector<Patient> patients;

	static const int M_MAX_NAME_LENGTH = 128;

public:
	Hospital();
	Hospital(Hospital&) = delete;
	Hospital(Hospital&&) = delete;
	~Hospital();

	void AddWard(const string ward_name) noexcept(false);
	const unsigned int getWardsNum()			const { return wards.size(); }
	TemplateArray<Ward>& getWards()				 { return wards; }


	Doctor* searchDoctorByID(const unsigned int& id) noexcept(false);
	Patient* searchPatientByID(const unsigned int& id);
	Patient* addPatient(const string name, unsigned int id, Date birth_date, int gender);
	

	
	ResearchCenter& getResearchCenter() { return research_center; }
	

	void saveHospital(const char* fileName)
	{
		ofstream outFile(fileName, ios::trunc);
		outFile << wards.size() << endl;

		for (int i = 0; i < wards.size(); i++)
			outFile << wards[i] << endl;

		int size = research_center.getNum_researchers();
		outFile << size << endl;
		for (int i = 0; i < research_center.getResearchers().size(); i++)
		{
			if (typeid(*research_center.getResearchers()[i]) == typeid(Researcher))
				outFile << *research_center.getResearchers()[i];
		}

		outFile.close();
	}


	void loadHospital(const char* fileName);
	

};