#include "Article.h"


//---------------------------------------------------------------//
void Article::setArticleName(const char* name)
{
	delete[]articleName;
	articleName = new char[strlen(name) + 1];
	strcpy(articleName, name);

}

//---------------------------------------------------------------//
void Article::setMagazineName(const char* name)
{
	delete[]magazineName;
	magazineName = new char[strlen(name) + 1];
	strcpy(magazineName, name);

}

//---------------------------------------------------------------//
Article::Article(Date date, const char* magaine, const char* name) 
	: m_publicationDate(date), magazineName(nullptr), articleName(nullptr)
{
	setArticleName(name);
	setMagazineName(magaine);

}

//---------------------------------------------------------------//
Article::~Article()
{
	delete[]magazineName;
	delete[]articleName;
}