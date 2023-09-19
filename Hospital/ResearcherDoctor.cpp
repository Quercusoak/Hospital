#include "ResearcherDoctor.h"


ResearcherDoctor::ResearcherDoctor(const string name, const string specialty)
	:Doctor(name, specialty), Staff(name), Researcher(name)
{}


//--------------------------------------------------------------------------------//
ResearcherDoctor::ResearcherDoctor(Doctor&& other)
	: Doctor(std::move(other)), Researcher(other.getName()), Staff(std::move(other))
{
	ResearcherDoctor* temp = dynamic_cast<ResearcherDoctor*>(&other);
	for (int i = 0; i < temp->getNumArticles(); i++)
		this->m_articles.push_back(temp->m_articles[i]);

	temp->m_articles.clear();
}


// --------------------------------------------------------------------------------//
void ResearcherDoctor::toOS(std::ostream& os) const
{
	Doctor::toOS(os);

	if (typeid(os) == typeid(ofstream))
		os << endl << this->m_articles.size() << endl;
	
	else
		os << ", " << endl << "Number of written Articles: " << this->m_articles.size();

	if(this->m_articles.size())
		this->toOSArticles(os);

}

// --------------------------------------------------------------------------------//
void ResearcherDoctor::fromOS(std::istream& in)
{
	Doctor::fromOS(in);
	Researcher::fromOS(in);
	in.get();

}
