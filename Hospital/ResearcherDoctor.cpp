#include "ResearcherDoctor.h"


ResearcherDoctor::ResearcherDoctor(const string name, const string specialty)
	:Doctor(name, specialty), Staff(name), Researcher(name) 
{}

//--------------------------------------------------------------------------------//
ResearcherDoctor::ResearcherDoctor(Doctor&& other)
	: Doctor(std::move(other)), Researcher(other.getName()), Staff(std::move(other))
{}

// --------------------------------------------------------------------------------//
void ResearcherDoctor::toOS(std::ostream& os) const
{
	Doctor::toOS(os);
	if (this->getNumArticles() > 0)
	{
		os << endl << ", Number of written Articles:" << this->getNumArticles();
		this->toOSArticles(os);
	}
}