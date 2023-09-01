#ifndef __RESEARCH_CENTER_H
#define __RESEARCH_CENTER_H

#include "Researcher.h"

class ResearchCenter
{
private:
	Researcher** researchers;
	int num_researchers;
	int max_researchers;

public:
	ResearchCenter();
	ResearchCenter(ResearchCenter&) = delete;
	ResearchCenter(ResearchCenter&&) = delete;
	~ResearchCenter();

	void AddResearcher(const char* name);
	void AddResearcherDoctor(Researcher&);


	Researcher** getResearchers()	const { return researchers; }
	int getNum_researchers()		const { return num_researchers; }
};

#endif __RESEARCH_CENTER_H