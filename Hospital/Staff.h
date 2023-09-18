
#ifndef __STAFF_H
#define __STAFF_H

#include "Person.h"

class Staff : public Person
{
protected:
	unsigned int workerId;

	Staff(const string);

private:
	static unsigned int counter;

public:
	unsigned int getNumOfWorkers()	const { return counter - 1000; }
	unsigned int getWorkerID()		const { return workerId; }

	Staff(const Staff&) = delete;
	Staff(Staff&&);
	virtual ~Staff();

	virtual void toOS(std::ostream& os)	const {}

	virtual void fromOs(std::istream& in) const {}


	friend std::ostream& operator<<(std::ostream& os, const Staff& staff)
	{		
		if (typeid(os) == typeid(ofstream))
			os << staff.name << endl << staff.workerId;
		else 
			os << staff.type()<< " " << staff.name << ", worker Id - " << staff.workerId;
		staff.toOS(os);
		return os;
	}



	virtual const string type()			const { return typeid(*this).name() + 6; };
	
};

#endif // !__STAFF_H