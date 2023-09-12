#include "Ward.h"


//---------------------------------------------------------------//
Ward::Ward(const string ward_name)
	
{
	

	this->name = ward_name;

	num_staff = 0;
	max_staff = 1;
	staff = new Staff * [max_staff];
	staff[0] = nullptr;

	num_doctors = 0;
	num_surgeons = 0;
}

//---------------------------------------------------------------//
 //deletes pointer array but not objects since those are part of hospital
Ward::~Ward()
{
	unsigned int i;


	for (i = 0; i < num_staff; ++i)
	{
		if (!(dynamic_cast<Researcher*>(staff[i]))) //researchers will be deleted in research center
			delete staff[i];
	}
	delete[] staff;

}


//---------------------------------------------------------------//
void Ward::AddPatient(Patient& patient)
{
	if (patients.size() == patients.capacity())
		patients.reserve(patients.capacity() * 2);

	patients.push_back(&patient);
}


//---------------------------------------------------------------//
void Ward::AddStaff(Staff&& newStaff)
{
	checkMaxSizeReached();

	Nurse* tmp = dynamic_cast<Nurse*>(&newStaff);
	if (tmp)
		staff[num_staff] = new 	Nurse(std::move(*tmp));
	else
	{
		Doctor* tmp = dynamic_cast<Doctor*>(&newStaff);
		if (tmp) //has to be true since staff is either nurse or doctor
			this->AddDoctor(std::move(*tmp));
		num_doctors++;
	}

	num_staff++;
}

//----------------------------------------------------------------------------------------------------//
void Ward::AddNurse(const string name, float yrs_of_experience)
{
	checkMaxSizeReached();

	staff[num_staff] = new 	Nurse(name, yrs_of_experience);
	num_staff++;
}

//----------------------------------------------------------------------------------------------------//
void Ward::AddDoctor(const string name, const string specialty)
{
	checkMaxSizeReached();

	staff[num_staff] = new Doctor(name, specialty);
	num_staff++;
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
			staff[num_staff] = new SurgeonResearcher(std::move(doctor));
			num_surgeons++;
		}
		else
		{
			staff[num_staff] = new ResearcherDoctor(std::move(doctor));
		}
	}
	else if (dynamic_cast<Surgeon*>(&doctor))
	{	
		staff[num_staff] = new Surgeon(std::move(doctor));
		num_surgeons++;
	}
	else
	{	
		staff[num_staff] = new Doctor(std::move(doctor));
	}
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


//----------------------------------------------------------------------------------------------------//
void Ward::operator+=(Staff&& other)
{
	AddStaff(std::move(other));
}


//----------------------------------------------------------------------------------------------------//
//NOT THE RIGHT PLACE
template <class T>
void addArray(vector<T*>& arr, T& obj)
{
	if (arr.capacity() == arr.size())
		arr.capacity() *= 2;
	arr.push_back(obj);
}