#include "SurgeonResearcher.h"


SurgeonResearcher::SurgeonResearcher(const string name, const string specialty)
	:Surgeon(name, specialty), Doctor(name, specialty), Researcher(name), Staff(name) 
{}


// --------------------------------------------------------------------------------//
SurgeonResearcher::SurgeonResearcher(Doctor&& other)
	:Surgeon(std::move(other)), Doctor(std::move(other)), Researcher(other.getName()), Staff(std::move(other))
{}

//--------------------------------------------------------------------------------//
void SurgeonResearcher::toOS(std::ostream& os) const 
{
	Surgeon::toOS(os);
	if (this->getNumArticles() > 0)
	{
		os << ", Number of written Articles:" << this->getNumArticles() ;
		this->toOSArticles(os);
	}
}