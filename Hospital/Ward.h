#ifndef __HOSPITALWARD_H
#define __HOSPITALWARD_H

#include "Doctor.h"
#include "Nurse.h"
#include "BaseFunc.h"
#include "Patient.h"
#include "Surgeon.h"
#include "SurgeonResearcher.h"
#include "ResearcherDoctor.h"


class Ward
{
private:
	string name;
	
	Staff** staff;
	unsigned int num_staff;
	unsigned int max_staff;

	unsigned int num_doctors;
	unsigned int num_surgeons;

	vector<Patient*> patients;


public:
	Ward(const string ward_name);
	Ward(const Ward&) = delete;
	Ward(Ward&&) = delete;
	~Ward();

	void AddStaff(Staff&&);
	void AddNurse(const string name, float yrs_of_experience);
	void AddDoctor(const string name, const string specialty);
	void AddDoctor(Doctor&&);


	Staff** getStaff()						const { return staff; }

	const unsigned int getNumStaff()		const { return num_staff; }
	const unsigned int getDoctorsNum()		const { return num_doctors; }
	const unsigned int getSurgeonsNum()		const { return num_surgeons; }

	
	void AddPatient(Patient&);
	const unsigned int getPatientsNum()		const { return patients.size(); }
	const vector<Patient*> getPatients()	const { return patients; }

	void operator+=(Staff&& other);

	const char* getName()	const { return name.c_str(); }

	void checkMaxSizeReached();

};

#endif __HOSPITALWARD_H