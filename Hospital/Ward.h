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

	vector<Staff*> staff;

	unsigned int num_doctors;
	unsigned int num_surgeons;

	vector<Patient*> patients;

	static const int M_MAX_NAME_LENGTH = 128;

public:
	Ward(const string ward_name = "");
	Ward(const Ward&) = delete;
	Ward(ifstream& in) { in >> *this; }
	Ward(Ward&&) noexcept;
	Ward& operator=(Ward&&) noexcept;

	~Ward();

	void AddStaff(Staff&&) noexcept(false);
	void AddNurse(const string name, float yrs_of_experience);
	void AddDoctor(const string name, const string specialty) noexcept(false);
	void AddDoctor(Doctor&&);


	const vector<Staff*>& getStaff() { return staff; }

	const unsigned int getNumStaff()		const { return staff.size(); }
	const unsigned int getDoctorsNum()		const { return num_doctors; }
	const unsigned int getSurgeonsNum()		const { return num_surgeons; }


	void AddPatient(Patient&);
	const unsigned int getPatientsNum()		const { return patients.size(); }
	const vector<Patient*> getPatients()	const { return patients; }

	void operator+=(Staff&& other) noexcept(false);

	const char* getName()	const { return name.c_str(); }

	void checkMaxSizeReached();


	


	friend std::ostream& operator<<(std::ostream& os, const Ward& ward)
	{
		os
			<< ward.name << endl
			<< ward.staff.size() << endl;
		for (unsigned int i = 0; i < ward.staff.size(); i++)
			os << typeid(*ward.staff[i]).name() + 6 << endl << *ward.staff[i] << endl;


		return os;
	}

	friend std::istream& operator>>(std::istream& in, Ward& ward)
	{
		char name[M_MAX_NAME_LENGTH];
		in.get();
		in.getline(name, M_MAX_NAME_LENGTH);
		ward.name = name;


		ward.num_surgeons = 0;
		ward.num_doctors = 0;
		
		return in;
	}



};

#endif __HOSPITALWARD_H