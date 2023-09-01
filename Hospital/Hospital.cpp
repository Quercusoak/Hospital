#include "Hospital.h"

//----------------------------------------------------------------------------------------------------//
Hospital::Hospital()
{
	num_wards = 0;
	max_wards = 1;
	wards = new Ward*[max_wards];
	wards[0] = nullptr;


	staff = new Staff* * [max_wards];
	staff[0] = nullptr;

	num_patients = 0;
	max_patients = 1;
	patients = new Patient * [max_patients];
	patients[0] = nullptr;

	wards_doctors = 0;
	wards_researchers = 0;
	wards_nurses = 0;


}

//----------------------------------------------------------------------------------------------------//
Hospital::~Hospital()
{
	unsigned int i;
	for (i = 0; i < num_wards; i++)
	{
		delete wards[i];
		delete staff[i];
	}

	delete staff;
}

//----------------------------------------------------------------------------------------------------//
void Hospital::AddWard(const char* ward_name)
{
	checkMaxSizeReached();

	wards[num_wards] = new Ward(ward_name, wards_doctors, wards_researchers, wards_nurses);

	staff[num_wards] = wards[num_wards]->getStaff();

	num_wards++;
}

//----------------------------------------------------------------------------------------------------//

Patient* Hospital::searchPatientByID(unsigned int& id)
{
	for (unsigned int i = 0; i < num_patients; i++)
	{
		if (patients[i]->getID() == id)
			return patients[i];
	}
	return nullptr;
}

//----------------------------------------------------------------------------------------------------//
Patient* Hospital::addPatient(const char* name, unsigned int id, Date birth_date, int gender)
{
	if (num_patients == max_patients)
	{
		max_patients *= 2;
		patients = (Patient**)rerealloc(patients, sizeof(Patient*), num_patients, max_patients);
	}

	patients[num_patients] = new Patient(name, id, birth_date, (Patient::eGender)gender);
	num_patients++;
	return patients[num_patients - 1];
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