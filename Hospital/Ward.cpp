#include "Ward.h"


//---------------------------------------------------------------//
Ward::Ward(const char* ward_name)
{
	name = new char[strlen(ward_name) + 1];
	strcpy(name, ward_name);

	num_staff = 0;
	max_staff = 1;
	staff = new Staff * [max_staff];
	staff[0] = nullptr;

	num_doctors = 0;

	num_patients = 0;
	max_patients_size = 1;
	patients = new Patient * [max_patients_size];
	patients[0] = nullptr;

}

//---------------------------------------------------------------//
 //deletes pointer array but not objects since those are part of hospital
Ward::~Ward()
{
	delete[]name;
	delete[] staff;
	delete[] patients;
}


//---------------------------------------------------------------//
void Ward::AddPatient(Patient& patient)
{
	if (num_patients == max_patients_size)
	{
		max_patients_size *= 2;
		this->patients = (Patient**)rerealloc(this->patients, sizeof(Patient*), num_patients, max_patients_size);
	}

	patients[num_patients] = &patient;
	num_patients++;
}


//---------------------------------------------------------------//
void Ward::AddStaff(Staff&& newStaff)
{
	checkMaxSizeReached();

	staff[num_staff] = &newStaff;
	num_staff++;

	if (typeid(newStaff) == typeid(Doctor))
	{
		num_doctors++;
	}
}

//----------------------------------------------------------------------------------------------------//
void Ward::AddNurse(const char* name, float yrs_of_experience)
{
	checkMaxSizeReached();

	staff[num_staff] = new 	Nurse(name, yrs_of_experience);
	num_staff++;
}

//----------------------------------------------------------------------------------------------------//
void Ward::AddDoctor(const char* name, const char* specialty)
{
	checkMaxSizeReached();

	staff[num_staff] = new 	Doctor(name, specialty);
	num_staff++;
	num_doctors++;
}

//----------------------------------------------------------------------------------------------------//
void Ward::AddSurgeon(Doctor&& doctor)
{
	checkMaxSizeReached();

	staff[num_staff] = new Surgeon(std::move(doctor));
	num_staff++;
	num_doctors++;
}


//----------------------------------------------------------------------------------------------------//
void Ward::checkMaxSizeReached()
{
	if (num_staff == max_staff)
	{
		max_staff *= 2;
		staff = (Staff**)rerealloc(staff, sizeof(Staff*), num_staff, max_staff);
	}
}