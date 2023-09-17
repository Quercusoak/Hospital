#include "Ward.h"


//---------------------------------------------------------------//
Ward::Ward(const string ward_name)
{
	this->name = ward_name;

	num_doctors = 0;
	num_surgeons = 0;
}

//---------------------------------------------------------------//
 //deletes pointer array but not objects since those are part of hospital
Ward::~Ward()
{

	patients.clear();

	vector<Staff*>::iterator itr = staff.begin();
	for (auto& elem : staff)
	{
		if (!(dynamic_cast<Researcher*>(elem)))
		{
			if (itr != staff.end())
				itr = staff.erase(itr);
			else
				staff.erase(itr);
		}
		else
			++itr;
	}

	staff.clear();

}


//---------------------------------------------------------------//
void Ward::AddPatient(Patient& patient)
{
	bool check = true;
	for (auto& elem : patients)
		if (elem == &patient) 
			check = false;


	if (check)
	{
		if (patients.size() == patients.capacity())
			patients.reserve(patients.capacity() * 2);

		patients.push_back(&patient);
	}
}


//---------------------------------------------------------------//
void Ward::AddStaff(Staff&& newStaff)
{
	checkMaxSizeReached();

	Nurse* tmp = dynamic_cast<Nurse*>(&newStaff);
	if (tmp)
		staff.push_back(new Nurse(std::move(*tmp)));
	else
	{
		Doctor* tmp = dynamic_cast<Doctor*>(&newStaff);
		if (tmp) //has to be true since staff is either nurse or doctor
			this->AddDoctor(std::move(*tmp));
		num_doctors++;
	}
}

//----------------------------------------------------------------------------------------------------//
void Ward::AddNurse(const string name, float yrs_of_experience)
{
	checkMaxSizeReached();

	staff.push_back(new Nurse(name, yrs_of_experience));
}

//----------------------------------------------------------------------------------------------------//
void Ward::AddDoctor(const string name, const string specialty)
{
	checkMaxSizeReached();

	staff.push_back(new Doctor(name, specialty));
	num_doctors++;
}

//----------------------------------------------------------------------------------------------------//
void Ward::AddDoctor(Doctor&& doctor)
{
	checkMaxSizeReached();

	if (dynamic_cast<Researcher*>(&doctor))
	{
		if (dynamic_cast<Surgeon*>(&doctor)) 
		{
			staff.push_back(new SurgeonResearcher(std::move(doctor)));
			num_surgeons++;
		}
		else
		{
			staff.push_back(new ResearcherDoctor(std::move(doctor)));
		}
	}
	else if (dynamic_cast<Surgeon*>(&doctor))
	{	
		staff.push_back(new Surgeon(std::move(doctor)));
		num_surgeons++;
	}
	else
	{	
		staff.push_back(new Doctor(std::move(doctor)));
	}
}



//----------------------------------------------------------------------------------------------------//
void Ward::checkMaxSizeReached()
{
	if (patients.size() == patients.capacity())
		patients.reserve(patients.capacity() * 2);
}


//----------------------------------------------------------------------------------------------------//
void Ward::operator+=(Staff&& other)
{
	AddStaff(std::move(other));
}


//---------------------------------------------------------------//
Ward::Ward(Ward&& other) noexcept
{
	std::swap(this->name, other.name);

	num_doctors = other.num_doctors;
	num_surgeons = other.num_surgeons;


	for (auto& elem : other.staff)
	{
		staff.push_back(elem);
	}
	other.staff.clear();

	for (auto& elem : other.patients)
	{
		patients.push_back(elem);
	}
	other.patients.clear();
}


//---------------------------------------------------------------//
Ward& Ward::operator=(Ward&& other) noexcept
{
	std::swap(this->name, other.name);

	num_doctors = other.num_doctors;
	num_surgeons = other.num_surgeons;


	for (auto& elem : other.staff)
	{
		staff.push_back(elem);
	}
	other.staff.clear();

	for (auto& elem : other.patients)
	{
		patients.push_back(elem);
	}
	other.patients.clear();

	return *this;
}
