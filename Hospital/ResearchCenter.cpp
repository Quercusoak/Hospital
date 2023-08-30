#include "ResearchCenter.h"
#include "BaseFunc.h"

//---------------------------------------------------------------//
ResearchCenter::ResearchCenter()
{
	num_researchers = 0;
	max_researchers = 1;
	researchers = new Researcher * [max_researchers];
	researchers[0] = nullptr;
}

//---------------------------------------------------------------//
ResearchCenter::~ResearchCenter()
{
	for (int i = 0; i < num_researchers; i++)
		delete researchers[i];
	delete[]researchers;
}

//---------------------------------------------------------------//
void ResearchCenter::AddResearcher(const char* name)
{
	if (num_researchers == max_researchers)
	{
		max_researchers *= 2;
		researchers = (Researcher**)rerealloc(researchers, sizeof(Researcher*), num_researchers, max_researchers);
	}

	researchers[num_researchers] = new Researcher(name);
	num_researchers++;

}


