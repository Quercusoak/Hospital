#include "SurgeonResearcher.h"


SurgeonResearcher::SurgeonResearcher(const string name, const string specialty)
	:Surgeon(name, specialty), Doctor(name, specialty), Researcher(name), Staff(name) 
{}


// --------------------------------------------------------------------------------//
SurgeonResearcher::SurgeonResearcher(Doctor&& other)
	:Surgeon(std::move(other)), Doctor(std::move(other)), Researcher(other.getName()), Staff(std::move(other))
{
	SurgeonResearcher* temp = dynamic_cast<SurgeonResearcher*>(&other);
	for (int i = 0; i < temp->getNumArticles(); i++)
		this->m_articles.push_back(temp->m_articles[i]);
	
	temp->m_articles.clear();

}

//--------------------------------------------------------------------------------//
void SurgeonResearcher::toOS(std::ostream& os) const 
{
	Surgeon::toOS(os);
	
	if (typeid(os) == typeid(ofstream))
		os << endl << this->m_articles.size() << endl;

	else
		os << ", " << endl << "Number of written Articles:" << this->m_articles.size();

	if (this->m_articles.size())
		this->toOSArticles(os);
}

//--------------------------------------------------------------------------------//
void SurgeonResearcher::fromOS(std::istream& in)
{
	Surgeon::fromOS(in);
	Researcher::fromOS(in);
	in.get();
}
