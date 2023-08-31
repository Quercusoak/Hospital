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
	//cout << "in Researcher::~Researcher d'tor, debugging line " << m_name << endl;

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
Researcher::Researcher(const Staff& base) : Staff(base)
{
	m_numArticles = 0;
	m_maxArticles = 1;
	m_articles = new Article * [m_maxArticles];
}