#ifndef __RESEARCH_CENTER_H
#define __RESEARCH_CENTER_H

#include "Researcher.h"

class ResearchCenter
{
private:
	vector<Researcher*> researchers;
	int num_researchers;

public:
	ResearchCenter();
	ResearchCenter(ResearchCenter&) = delete;
	ResearchCenter(ResearchCenter&&) = delete;
	~ResearchCenter();

	void AddResearcher(Researcher& other);
	


	const vector<Researcher*>& getResearchers()		{ return researchers; }
	int getNum_researchers()			  const { return num_researchers; }
};

#endif __RESEARCH_CENTER_H