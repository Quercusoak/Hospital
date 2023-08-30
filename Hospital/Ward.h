#ifndef __HOSPITALWARD_H
#define __HOSPITALWARD_H
#include "Doctor.h"
#include "Nurse.h"
#include "BaseFunc.h"

class Patient;

class Ward
{
private:
	char* name;
	
	Doctor** doctors;
	unsigned int num_doctors;
	unsigned int max_doctors_size;
	
	Nurse** nurses;
	unsigned int num_nurses;
	unsigned int max_nurse_size;

	Patient** patients;
	unsigned int num_patients;
	unsigned int max_patients_size;


public:
	Ward(const char* ward_name);
	Ward(const Ward&) = delete;
	Ward(const Ward&&) = delete;
	~Ward();

	void AddDoctor(Doctor&);
	void AddNurse(Nurse&);
	void AddPatient(Patient&);

	const unsigned int getDoctorsNum()	const { return num_doctors; }
	Doctor* const* getDoctors()				const { return doctors; }

	const unsigned int getPatientsNum()	const { return num_patients; }
	Patient* const* getPatients()				const { return patients; }

	const char* getName()	const { return name; }

};

#endif __HOSPITALWARD_H