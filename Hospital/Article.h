#ifndef __ARTICLE_H
#define __ARTICLE_H

#include "Date.h"

class Article
{
private:
	Date m_publicationDate; 
	string magazineName;
	string articleName;

	static const int M_MAX_NAME_LENGTH = 128;
	
public:
	Article() = default;
	Article(const Date date, const string magaine, const string name) : m_publicationDate(date), magazineName(magaine), articleName(name)	{}
	Article(ifstream& in) { in >> *this; }
	Article(const Article&) = default;
	Article(Article&&) = default;




	const Date getDate()			const { return m_publicationDate; }
	const string getMagazineName()	const { return magazineName; }
	const string getArticleName()	const { return articleName; }



	friend std::ostream& operator<<(std::ostream& os, const Article& article)
	{
		if (typeid(os) == typeid(ofstream))
			os
				<< article.magazineName << endl
				<< article.articleName << endl
				<< article.m_publicationDate;

		else
			os 
				<< "Magazine Name - " << article.magazineName << "\n"
				<< "Article Name - " << article.articleName << "\n"
				<< "Date - " << article.m_publicationDate;
		return os;
	}

	friend std::istream& operator>>(std::istream& in, Article& article)
	{
		char strInput[M_MAX_NAME_LENGTH];
		in.getline(strInput, M_MAX_NAME_LENGTH);
		article.magazineName = strInput;
		in.getline(strInput, M_MAX_NAME_LENGTH);
		article.articleName = strInput;
		in >> article.m_publicationDate;
		in.get();
		return in;
	}
};





#endif //__ARTICLE_H