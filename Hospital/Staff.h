
#ifndef __STAFF_H
#define __STAFF_H

#include "Person.h"

class Staff : public Person
{
protected:
	unsigned int workerId;

	Staff(const char*);
	Staff(const Staff&); //completly useless, only workerId here, and therefore, normal cpy would had worked...
	virtual ~Staff();

private:
	static unsigned int counter;

public:
	unsigned int getNumOfWorkers()	const { return counter - 1000; }
	unsigned int getWorkerID()		const { return workerId; }



	friend std::ostream& operator<<(std::ostream& os, const Staff& staff)
	{
		os << "Name - " << staff.name << ", worker Id - " << staff.workerId;
		staff.toOS(os);
		return os;
	}


	virtual void toOS(std::ostream& os) const {}


	
};

#endif // !__STAFF_H