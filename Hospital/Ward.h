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
	char* name;
	
	Staff** staff;
	unsigned int num_staff;
	unsigned int max_staff;

	unsigned int num_doctors;

	Patient** patients;
	unsigned int num_patients;
	unsigned int max_patients_size;


public:
	Ward(const char* ward_name);
	Ward(const Ward&) = delete;
	Ward(Ward&&) = delete;
	~Ward();

	void AddStaff(Staff&&);
	void AddNurse(const char* name, float yrs_of_experience);
	void AddDoctor(const char* name, const char* specialty);
	void AddDoctor(Doctor&&);


	Staff** getStaff()						const { return staff; }

	const unsigned int getNumStaff()		const { return num_staff; }
	const unsigned int getDoctorsNum()		const { return num_doctors; }
	
	void AddPatient(Patient&);
	const unsigned int getPatientsNum()		const { return num_patients; }
	Patient* const* getPatients()			const { return patients; }

	void operator+=(const Staff& other);
	void operator+=(Staff&& other);

	const char* getName()	const { return name; }

	void checkMaxSizeReached();

};

#endif __HOSPITALWARD_H