#include "Hospital.h"

//----------------------------------------------------------------------------------------------------//
Hospital::Hospital()
{
}

//----------------------------------------------------------------------------------------------------//
Hospital::~Hospital()
{
	vector<Patient>::iterator itr = patients.begin();
	for (auto& elem : patients)
	{
		if (itr != patients.end())
			itr = patients.erase(itr);
		else
			patients.erase(itr);

	}
	patients.clear();
}

//----------------------------------------------------------------------------------------------------//
void Hospital::AddWard(const char* ward_name)
{
	wards.add(Ward(ward_name));
}

//----------------------------------------------------------------------------------------------------//

Patient* Hospital::searchPatientByID(unsigned int& id)
{
	vector<Patient>::iterator i = patients.begin();
	vector<Patient>::iterator end = patients.end();

	for (; i != end; ++i)
	{
		if ((*i).getID() == id)
			return &(*i);
	}
	return nullptr;
}

//----------------------------------------------------------------------------------------------------//
Patient* Hospital::addPatient(const string name, unsigned int id, Date birth_date, int gender)
{
	patients.push_back(std::move(Patient(name, id, birth_date, (Patient::eGender)gender)));
	return &*(--patients.end());
}
