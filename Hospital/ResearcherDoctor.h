#ifndef __RESEARCHER_DOCOTR_H
#define __RESEARCHER_DOCTOR_H

#include "Doctor.h"
#include "Researcher.h"

class ResearcherDoctor : public Doctor, public Researcher
{
public:
	ResearcherDoctor(const char* name, const char* specialty);

	ResearcherDoctor(Doctor&& other);

	~ResearcherDoctor() {};

	virtual void toOS(std::ostream& os) const override;

	virtual const char* type() const override { return "Researcher Doctor"; }

};




#endif