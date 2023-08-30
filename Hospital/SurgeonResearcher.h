#ifndef __SURGEON_RESEARCHER_H
#define __SURGEON_RESEARCHER_H

#include "Surgeon.h"
#include "Researcher.h"

class SurgeonResearcher : public Surgeon, public Researcher
{
public:
	SurgeonResearcher(const char* name, const char* specialty)
		:Surgeon(name, specialty),Doctor(name,specialty), Researcher(name), Staff(name) {};

};



#endif