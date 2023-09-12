#ifndef __ARTICLE_H
#define __ARTICLE_H

#include <iostream>
#pragma warning(disable: 4996)

#include "Date.h"

class Article
{
private:
	Date m_publicationDate; 
	string magazineName;
	string articleName;

public:
	Article(Date date,const string magaine,const string name);
	


	void setMagazineName(const string name) { this->magazineName = name; }
	void setArticleName(const string name)	{ this->articleName = name; }
	;


	const Date getDate()			const { return m_publicationDate; }
	const char* getMagazineName()	const { return magazineName.c_str(); }
	const char* getArticleName()	const { return articleName.c_str(); }


	friend std::ostream& operator<<(std::ostream& os, const Article& article)
	{
		os 
			<< "Magazine Name - " << article.magazineName << "\n"
			<< "Article Name - " << article.articleName << "\n"
			<< "Date - " << article.m_publicationDate;
		return os;
	}
};





#endif //__ARTICLE_H