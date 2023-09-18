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
	if (typeid(os) == typeid(ofstream))
		os << endl << this->m_articles.size() << endl;
	
	else
		os << ", Number of written Articles:" << this->m_articles.size();

	if(this->m_articles.size())
		this->toOSArticles(os);

}

// --------------------------------------------------------------------------------//
void ResearcherDoctor::fromOS(std::istream& in)
{
	Doctor::fromOS(in);
	Researcher::fromOS(in);
}
