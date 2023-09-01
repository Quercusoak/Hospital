#ifndef __SURGEON_RESEARCHER_H
#define __SURGEON_RESEARCHER_H

#include "Surgeon.h"
#include "Researcher.h"

class SurgeonResearcher : public Surgeon, public Researcher
{
public:
	SurgeonResearcher(const char* name, const char* specialty)
		:Surgeon(name, specialty), Doctor(name, specialty), Researcher(name), Staff(name) {};

	SurgeonResearcher(Doctor&& other)
		:Surgeon(std::move(other)), Doctor(std::move(other)), Researcher(other.getName()), Staff(std::move(other))
	{
	}

	virtual void toOS(std::ostream& os) const override
	{

		os << ", Job - Surgeon Researcher ,Specialty - " << m_specialty << ", Number of Surgeries Performed: " << num_surgeries;
		if(this->getNumArticles() > 0)
		{
			os << "Number of written Articles:" << this->getNumArticles() << endl;
			this->toOSArticles(os);
		}
	}
};



#endif