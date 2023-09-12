#ifndef __RESEARCHER_DOCOTR_H
#define __RESEARCHER_DOCTOR_H

#include "Doctor.h"
#include "Researcher.h"

class ResearcherDoctor : public Doctor, public Researcher
{
public:
	ResearcherDoctor(const string name, const string specialty);

	ResearcherDoctor(Doctor&& other);

	~ResearcherDoctor() {};

	virtual void toOS(std::ostream& os) const override;

	virtual const string type() const override { return "Researcher Doctor"; }

};




#endif