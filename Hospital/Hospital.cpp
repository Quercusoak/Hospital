#include "Hospital.h"

//----------------------------------------------------------------------------------------------------//
Hospital::Hospital()
{
}

//----------------------------------------------------------------------------------------------------//
Hospital::~Hospital()
{
	int size = patients.size();
	for (int i = 0; i < size; i++) delete patients[i];
	patients.clear();
}

//----------------------------------------------------------------------------------------------------//
void Hospital::AddWard(const string ward_name)
{
	wards.add(Ward(ward_name));
}

//----------------------------------------------------------------------------------------------------//
Doctor* Hospital::searchDoctorByID(const unsigned int& id) noexcept(false)
{

	for (unsigned int i = 0; i < wards.size(); i++)
	{
		int size = wards[i].getStaff().size();
		for (unsigned int k = 0; i < size; k++)
			if (wards[i].getStaff()[k]->getWorkerID() == id)
			{
				Doctor* ret = dynamic_cast<Doctor*>(wards[i].getStaff()[k]);
				if (ret) return ret;
				else throw "Selected id is not of a doctor.";
			}
	}
	throw "Doctor not found.";
}

//----------------------------------------------------------------------------------------------------//

Patient* Hospital::searchPatientByID(const unsigned int& id)
{
	
	vector<Patient*>::iterator found = find_if(patients.begin(), patients.end(), [id](Patient* patient) -> bool {return *patient == id; });
	
	if (found == patients.end() || &found == NULL)
		return nullptr;
	
	return (*found);
}

//----------------------------------------------------------------------------------------------------//
Patient* Hospital::addPatient(const string name, unsigned int id, Date birth_date, int gender)
{
	patients.push_back(new Patient(name, id, birth_date, (Patient::eGender)gender));
	return *(--patients.end());
}

//----------------------------------------------------------------------------------------------------//
void Hospital::loadHospital(const char* fileName)
{
	ifstream inFile(fileName, ios::in);
	if (inFile.peek() == std::ifstream::traits_type::eof())
		return;
	unsigned int numOfWards;
	inFile >> numOfWards;
	
	for (unsigned int i = 0; i < numOfWards; i++)
	{
		wards.add(Ward(inFile));
		
		unsigned int numOfStaffs;
		inFile >> numOfStaffs;
		inFile.get();
		for (unsigned int k = 0; k < numOfStaffs; k++)
		{
			char type[M_MAX_NAME_LENGTH];
			inFile.getline(type, M_MAX_NAME_LENGTH);

			

			Staff* newStaff = NULL;
			if (strcmp(type, typeid(Nurse).name() + 6) == 0)
				newStaff = new Nurse(inFile);
			if (strcmp(type, typeid(Surgeon).name() + 6) == 0)
				newStaff = new Surgeon(inFile);
			if (strcmp(type, typeid(Doctor).name() + 6) == 0)
				newStaff = new Doctor(inFile);
			if (strcmp(type, typeid(SurgeonResearcher).name() + 6) == 0)
			{
				newStaff = new SurgeonResearcher(inFile);
			}
			if (strcmp(type, typeid(ResearcherDoctor).name() + 6) == 0)
			{
				newStaff = new ResearcherDoctor(inFile);
			}


			wards[wards.size() - 1].AddStaff(std::move(*newStaff));
			Researcher* temp = dynamic_cast<Researcher*>(*(--wards[wards.size() - 1].getStaff().end()));
			if (temp)
				research_center.AddResearcher(*temp);
			delete newStaff;
		}
		
	}
	


	unsigned int numOfResearchers;
	inFile >> numOfResearchers;
	inFile.get();
	for (unsigned int i = 0; i < numOfResearchers; i++) 
	{
		Researcher* newResearcher = new Researcher(inFile);
		research_center.AddResearcher(*newResearcher);
	}

	inFile.close();
}