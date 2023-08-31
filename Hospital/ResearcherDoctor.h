#ifndef __RESEARCHER_DOCOTR_H
#define __RESEARCHER_DOCTOR_H

#include "Doctor.h"
#include "Researcher.h"

class ResearcherDoctor : public Doctor, public Researcher
{
public:
	ResearcherDoctor(const char* name, const char* specialty)
		:Doctor(name, specialty), Staff(name), Researcher(name) {};
	~ResearcherDoctor() {};
};


#endif