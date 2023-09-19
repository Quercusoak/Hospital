#include "Researcher.h"

//---------------------------------------------------------------//
Researcher::Researcher(const string name) noexcept(false) : Staff(name)
{
	m_numArticles = 0;

}

//---------------------------------------------------------------//
Researcher::~Researcher()
{
	for (unsigned int i = 0; i < m_numArticles; i++) delete m_articles[i];
	m_articles.clear();
}

//---------------------------------------------------------------//
void Researcher::addArticle(Article& data) 
{
	bool checkRepeats = true;
	for (unsigned int i = 0; i < m_numArticles; i++)
		if (m_articles[i] == &data) checkRepeats = false;
	if (checkRepeats) {
		

		m_articles.push_back(&data);
		m_numArticles++;
	}
}


//---------------------------------------------------------------//
int Researcher::operator>(const Researcher& other)
{
	int res;
	unsigned int otherArticles = other.getNumArticles();

	if (m_numArticles > otherArticles)
		res = 1;
	else if (m_numArticles < otherArticles)
		res = -1;
	else
		res = 0;

	return res;
}