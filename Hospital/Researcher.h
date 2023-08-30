#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "BaseFunc.h"
#include "Staff.h"

class Article;

class Researcher :virtual public Staff
{
private:

	Article** m_articles;
	unsigned int m_maxArticles;
	unsigned int m_numArticles;

public:
	Researcher(const char* name);
	Researcher(const Staff& base);///unsure about necessity
	Researcher(const Researcher&) = delete;
	Researcher(Researcher&&) = delete;
	virtual ~Researcher();

	void addArticle(Article& data);

	int getNumArticles()					const { return m_numArticles; }
	Article* getArticle(int placmeant)		const { return m_articles[placmeant]; }
	Article** getArticles()					const { return m_articles; }

};



#endif //__RESEARCHER_H