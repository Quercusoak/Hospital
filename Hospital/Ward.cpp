#include "Ward.h"


//---------------------------------------------------------------//
Ward::Ward(const char* ward_name)
{
	name = new char[strlen(ward_name) + 1];
	strcpy(name, ward_name);

	num_nurses = 0;
	max_nurse_size = 1;
	nurses = new Nurse * [max_nurse_size];
	nurses[0] = nullptr;

	num_doctors = 0;
	max_doctors_size = 1;
	doctors = new Doctor * [max_doctors_size];
	doctors[0] = nullptr;

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
	delete[] nurses;
	delete[] doctors;
	delete[] patients;
}

//---------------------------------------------------------------//
void Ward::AddNurse(Nurse& nurse)
{
	if (num_nurses == max_nurse_size)
	{
		max_nurse_size *= 2;
		nurses = (Nurse**)rerealloc(nurses, sizeof(Nurse*), num_nurses,  max_nurse_size);
	}

	nurses[num_nurses] = &nurse;
	num_nurses++;

}

//---------------------------------------------------------------//
void Ward::AddDoctor(Doctor& doctor)
{
	if (num_doctors == max_doctors_size)
	{
		max_doctors_size *= 2;
		doctors = (Doctor**)rerealloc(doctors, sizeof(Doctor*), num_doctors, max_doctors_size);
	}

	doctors[num_doctors] = &doctor;
	num_doctors++;
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