
#ifndef __STAFF_H
#define __STAFF_H

#include "Person.h"

class Staff : public Person
{
protected:
	unsigned int workerId;

	Staff(const string) noexcept(false);

private:
	static unsigned int counter;

public:
	unsigned int getNumOfWorkers()	const { return counter - 1000; }
	unsigned int getWorkerID()		const { return workerId; }

	Staff(const Staff&) = delete;
	Staff(Staff&& other) noexcept;
	virtual ~Staff();

	Staff& operator=(Staff&& other) noexcept;


	friend std::ostream& operator<<(std::ostream& os, const Staff& staff)
	{		
		os << staff.type()<< " " << staff.name << ", worker Id - " << staff.workerId;
		staff.toOS(os);
		return os;
	}


	virtual void toOS(std::ostream& os)	const {}

	virtual const string type()			const { return typeid(*this).name() + 6; };
	
};

#endif // !__STAFF_H