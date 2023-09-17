#include "Hospital.h"

//----------------------------------------------------------------------------------------------------//
Hospital::Hospital()
{
	num_wards = 0;
	max_wards = 1;
	wards = new Ward * [max_wards];
	wards[0] = nullptr;
}

//----------------------------------------------------------------------------------------------------//
Hospital::~Hospital()
{
	unsigned int i;
	for (i = 0; i < num_wards; i++)
	{
		delete wards[i];
	}
	delete[] wards;


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
	checkMaxSizeReached();

	wards[num_wards] = new Ward(ward_name);

	num_wards++;
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

//----------------------------------------------------------------------------------------------------//
void Hospital::checkMaxSizeReached()
{

	if (num_wards == max_wards)
	{
		max_wards *= 2;
		wards = (Ward**)rerealloc(wards, sizeof(Ward*), num_wards, max_wards);
	}
}