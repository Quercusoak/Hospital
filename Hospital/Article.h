#ifndef __ARTICLE_H
#define __ARTICLE_H

#include "Date.h"

class Article
{
private:
	Date m_publicationDate; 
	char* magazineName;
	char* articleName;

public:
	Article(Date date,const char* magaine,const char* name);
	Article(const Article&) = delete;
	Article(Article&&) = delete;
	~Article();


	void setMagazineName(const char* name);
	void setArticleName(const char* name);


	const Date getDate()			const { return m_publicationDate; }
	const char* getMagazineName()	const { return magazineName; }
	const char* getArticleName()	const { return articleName; }


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