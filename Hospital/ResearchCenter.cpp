#include "ResearchCenter.h"
#include "BaseFunc.h"

//---------------------------------------------------------------//
ResearchCenter::ResearchCenter()
{
	num_researchers = 0;
}

//---------------------------------------------------------------//
ResearchCenter::~ResearchCenter()
{
	for (int i = 0; i < num_researchers; i++)
		delete researchers[i];
	researchers.clear();
}

//---------------------------------------------------------------//
void ResearchCenter::AddResearcher(Researcher& other)
{
	

	researchers.push_back(&other);
	if(typeid(other) == typeid(Researcher))
		num_researchers++;

}


//---------------------------------------------------------------//
