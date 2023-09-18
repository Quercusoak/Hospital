
#ifndef __STAFF_H
#define __STAFF_H

#include "Person.h"

class Staff : public Person
{
protected:
	unsigned int workerId;

	Staff() { counter++; }
	Staff(const string);
	Staff(ifstream& in) 
	{
		in >> *this;
		counter++; // expectd to work before any other adding, and therefor, older id counter is trusted
	}

private:
	static unsigned int counter;

public:
	unsigned int getNumOfWorkers()	const { return counter - 1000; }
	unsigned int getWorkerID()		const { return workerId; }

	Staff(const Staff&) = delete;
	Staff(Staff&& other) noexcept;
	virtual ~Staff();

	Staff& operator=(Staff&& other) noexcept;



	virtual void toOS(std::ostream& os)	const {}

	virtual void fromOS(std::istream& in) {}


	friend std::ostream& operator<<(std::ostream& os, const Staff& staff)
	{		

		if (typeid(os) == typeid(ofstream))
			os 
				<< staff.name << endl 
				<< staff.workerId;
		else 
			os << staff.type() << " " << staff.name << ", worker Id - " << staff.workerId;

		staff.toOS(os);
		return os;
	}

	friend std::istream& operator>>(std::istream& in, Staff& staff)
	{
		char name[M_MAX_NAME_LENGTH];
		in.getline(name, M_MAX_NAME_LENGTH);
		staff.name = name;
		in >> staff.workerId;
		
		staff.fromOS(in);
		return in;
	}

	virtual const string type()			const { return typeid(*this).name() + 6; };
	
};

#endif // !__STAFF_H