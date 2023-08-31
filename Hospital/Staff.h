
#ifndef __STAFF_H
#define __STAFF_H

#include "Person.h"

class Staff : public Person
{
protected:
	unsigned int workerId;

	Staff(const char*);


private:
	static unsigned int counter;

public:
	unsigned int getNumOfWorkers()	const { return counter - 1000; }
	unsigned int getWorkerID()		const { return workerId; }
	virtual ~Staff();

	virtual void toOS(std::ostream& os) const {}


	friend std::ostream& operator<<(std::ostream& os, const Staff& staff)
	{
		os << "Name - " << staff.name << ", worker Id - " << staff.workerId;
		staff.toOS(os);
		return os;
	}

};

#endif // !__STAFF_H