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
void Hospital::AddWard(const string ward_name) noexcept(false)
{
	if (ward_name == "")
		throw string("Ward name is a required field.");

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
Patient* Hospital::addPatient(const string name, unsigned int id, Date birth_date, int gender) noexcept(false)
{

	try
	{
		patients.push_back(std::move(Patient(name, id, birth_date, gender)));
	}
	catch (string& e)
	{
		cout << e << endl;
	}
	return &*(--patients.end());
}
