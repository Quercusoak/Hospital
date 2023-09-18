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
	
	if (typeid(os) == typeid(ofstream))
		os << endl << this->m_articles.size() << endl;

	else
		os << ", Number of written Articles:" << this->m_articles.size();

	if (this->m_articles.size())
		this->toOSArticles(os);
}

//--------------------------------------------------------------------------------//
void SurgeonResearcher::fromOS(std::istream& in)
{
	Surgeon::fromOS(in);
	Researcher::fromOS(in);
}
