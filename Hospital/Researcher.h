#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "BaseFunc.h"
#include "Staff.h"
#include "Article.h"
#include <vector>

class Researcher :virtual public Staff
{
protected:
	std::vector<Article*> m_articles;
	Researcher() = default;

public:
	Researcher(const string name);
	Researcher(ifstream& in) { in >> *this; }
	Researcher(const Researcher&) = delete;
	Researcher(Researcher&&) = default;
	virtual ~Researcher();

	void addArticle(Article& data);

	int getNumArticles()					const { return m_articles.size(); }
	Article& getArticle(int placmeant)		const { return *m_articles[placmeant]; }
	std::vector<Article*> getArticles()					const { return m_articles; }


	int operator>(const Researcher& other);



	virtual void toOS(std::ostream& os) const override
	{

		if (typeid(os) == typeid(ofstream))
			os << " " << m_articles.size() << endl;
		else {
			os << ", Number of written Articles: "
				<< m_articles.size() << ".";
			if (m_articles.size() == 0)
				return;
		}
		toOSArticles(os);
	}

	void toOSArticles(std::ostream& os) const
	{
		if (typeid(os) == typeid(ofstream))
		{
			for (unsigned int i = 0; i < m_articles.size(); i++) {
				os << getArticle(i) << "\n";
			}
		}
		else
		{
			os << endl << "Articles: " << endl;
			for (unsigned int i = 0; i < m_articles.size(); i++) {
				cout << i + 1 << ")" << getArticle(i) << "\n";
			}
		}
	}

	virtual void fromOS(std::istream& in) override
	{
		unsigned int intInput;
		in >> intInput;
		in.get();

		for (unsigned int i = 0; i < intInput; i++) {
			Article* load = new Article();
			in >> *load;
			m_articles.push_back(load);
		}
	}


	
};



#endif //__RESEARCHER_H