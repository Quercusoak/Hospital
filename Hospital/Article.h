#ifndef __ARTICLE_H
#define __ARTICLE_H

#include <iostream>
#pragma warning(disable: 4996)
#include <string>
#include "Date.h"

class Article
{
private:
	Date m_publicationDate; 
	string magazineName;
	string articleName;

public:
	Article(Date date,const string magaine,const string name);
	Article(const Article&) = delete;
	Article(Article&&) = delete;


	const Date getDate()			const { return m_publicationDate; }
	const string getMagazineName()	const { return magazineName; }
	const string getArticleName()	const { return articleName; }


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