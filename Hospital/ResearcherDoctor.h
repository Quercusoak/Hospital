#ifndef __RESEARCHER_DOCOTR_H
#define __RESEARCHER_DOCTOR_H

#include "Doctor.h"
#include "Researcher.h"

class ResearcherDoctor : public Doctor, public Researcher
{
public:
	ResearcherDoctor(const char* name, const char* specialty)
		:Doctor(name, specialty), Staff(name), Researcher(name) {};

	ResearcherDoctor(Doctor&& other)
		: Doctor(std::move(other)), Researcher(other.getName()), Staff(std::move(other))
	{
	}

	~ResearcherDoctor() {};

	virtual void toOS(std::ostream& os) const override
	{
		os << ", Job - Researcher Doctor, Specialty - " << m_specialty << ", ";
		this->toOSArticles(os);
	}

};


#endif