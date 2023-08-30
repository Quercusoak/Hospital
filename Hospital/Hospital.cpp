#include "Hospital.h"

//----------------------------------------------------------------------------------------------------//
Hospital::Hospital()
{
	num_wards = 0;
	max_wards = 1;
	wards = new Ward*[max_wards];
	wards[0] = nullptr;

	num_nurses = 0;
	max_nurse_size = 1;
	nurses = new Nurse * [max_nurse_size];
	nurses[0] = nullptr;

	num_doctors = 0;
	max_doctors_size = 1;
	doctors = new Doctor * [max_doctors_size];
	doctors[0] = nullptr;

	num_patients = 0;
	max_patients = 1;
	patients = new Patient * [max_patients];
	patients[0] = nullptr;
}

//----------------------------------------------------------------------------------------------------//
Hospital::~Hospital()
{
	unsigned int i;
	for (i = 0; i < num_nurses; i++)
	{
		delete nurses[i];
	}
	for (i = 0; i < num_doctors; i++)
	{
		delete doctors[i];
	}
	delete nurses;
	delete doctors;
}

//----------------------------------------------------------------------------------------------------//
void Hospital::AddWard(const char* ward_name)
{
	if (num_wards == max_wards)
	{
		max_wards *= 2;
		wards = (Ward**)rerealloc(wards, sizeof(Ward*),num_wards, max_wards);
	}

	wards[num_wards] = new Ward(ward_name);
	num_wards++;
}

//----------------------------------------------------------------------------------------------------//
void Hospital::AddNurse(const char* name, float yrs_of_experience, Ward& ward)
{
	if (num_nurses == max_nurse_size)
	{
		max_nurse_size *= 2;
		nurses = (Nurse**)rerealloc(nurses, sizeof(Nurse*), num_nurses, max_nurse_size);
	}

	nurses[num_nurses] = new Nurse(name, yrs_of_experience);
	ward.AddNurse(*(nurses[num_nurses]));
	num_nurses++;
}

//----------------------------------------------------------------------------------------------------//
void Hospital::AddDoctor(const char* name, const char* specialty, Ward& ward)
{
	if (num_doctors == max_doctors_size)
	{
		max_doctors_size *= 2;
		doctors = (Doctor**)rerealloc(doctors, sizeof(Doctor*), num_doctors, max_doctors_size);
	}

	doctors[num_doctors] = new Doctor(name, specialty);
	ward.AddDoctor(*(doctors[num_doctors]));
	num_doctors++;
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
//function to check for duplicate worker id in hospital staff
bool Hospital::searchWorkerId(unsigned int data) const
{
	Researcher** researchers = this->research_center.getResearchers();
	int maxSearch;

	for (int i = 0, maxSearch = this->research_center.getNum_researchers(); i < maxSearch; i++)
		if (researchers[i]->getWorkerID() == data) 
			return false;

	for (int i = 0, maxSearch = this->num_doctors; i < maxSearch; i++)
		if (this->doctors[i]->getWorkerID() == data) 
			return false;

	for (int i = 0, maxSearch = this->num_nurses; i < maxSearch; i++)
		if (this->nurses[i]->getWorkerID() == data)
			return false;
	
	return true;
}
