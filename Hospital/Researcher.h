#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "BaseFunc.h"
#include "Staff.h"
#include "Article.h"

class Researcher :virtual public Staff
{
private:

	Article** m_articles;
	unsigned int m_maxArticles;
	unsigned int m_numArticles;

public:
	Researcher(const char* name);
	Researcher(const Researcher&) = delete;
	Researcher(Researcher&&);
	virtual ~Researcher();

	void addArticle(Article& data);

	int getNumArticles()					const { return m_numArticles; }
	Article& getArticle(int placmeant)		const { return *m_articles[placmeant]; }
	Article** getArticles()					const { return m_articles; }


	

	virtual void toOS(std::ostream& os) const override
	{
		os << ", Job - Researcher" << ", Number of written Articles: "
			<< m_numArticles << ".";
		if (m_numArticles == 0)
			return;

		toOSArticles(os);
	}

	void toOSArticles(std::ostream& os) const
	{
		os << endl << "Articles: " << endl;
		for (unsigned int i = 0; i < m_numArticles; i++) {
			cout << i + 1 << ")" << getArticle(i) << "\n";
		}
	}
};



#endif //__RESEARCHER_H