#ifndef __RESEARCH_CENTER_H
#define __RESEARCH_CENTER_H

#include "Researcher.h"
#include <algorithm>

#define BY_NAME 0
#define BY_ID 1


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
	
	void sortResearchers(unsigned int func);


	const vector<Researcher*>& getResearchers()		{ return researchers; }
	int getNum_researchers()			  const { return num_researchers; }
};

#endif __RESEARCH_CENTER_H