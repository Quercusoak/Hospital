
#ifndef __STAFF_H
#define __STAFF_H

#include "Person.h"

class Staff : public Person
{
protected:
	unsigned int workerId;

	Staff(const char*);

	virtual ~Staff();


private:
	static unsigned int counter;

public:
	unsigned int getNumOfWorkers()	const { return counter - 1000; }
	unsigned int getWorkerID()		const { return workerId; }

};

#endif // !__STAFF_H
