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
void ResearchCenter::sortResearchers(unsigned int func)
{
	
	switch (func) 
	{
	case BY_NAME:
		sort(researchers.begin(), researchers.end(), [](Researcher* first, Researcher* second) 
			{
				if (strcmp(first->getName(), second->getName()) >= 0)
					return false;
				else
					return true;
			});
		break;

	case BY_ID:
		sort(researchers.begin(), researchers.end(), [](Researcher* first, Researcher* second) {return first->getWorkerID() < second->getWorkerID(); });
		break;

	default:
		break;
	}
}
