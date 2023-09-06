#include "Researcher.h"

//---------------------------------------------------------------//
Researcher::Researcher(const char* name): Staff(name)
{
	m_numArticles = 0;
	m_maxArticles = 1;
	m_articles = new Article * [m_maxArticles];

}

//---------------------------------------------------------------//
Researcher::~Researcher()
{
	for (unsigned int i = 0; i < m_numArticles; i++) delete m_articles[i];
	delete[]m_articles;
}

//---------------------------------------------------------------//
void Researcher::addArticle(Article& data) 
{
	bool checkRepeats = true;
	for (unsigned int i = 0; i < m_numArticles; i++)
		if (m_articles[i] == &data) checkRepeats = false;
	if (checkRepeats) {
		if (m_numArticles == m_maxArticles) {

			m_maxArticles *= 2;
			m_articles = (Article**)rerealloc(m_articles, sizeof(Article*), m_numArticles, m_maxArticles);
		}

		m_articles[m_numArticles] = &data;
		m_numArticles++;
	}
}

//---------------------------------------------------------------//
Researcher::Researcher(Researcher&& other) : Staff(std::move(other))
{
	m_numArticles = 0;
	m_maxArticles = 1;
	m_articles = new Article * [m_maxArticles];
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