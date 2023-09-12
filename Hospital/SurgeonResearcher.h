#ifndef __SURGEON_RESEARCHER_H
#define __SURGEON_RESEARCHER_H

#include "Surgeon.h"
#include "Researcher.h"

class SurgeonResearcher : public Surgeon, public Researcher
{
public:

	virtual void toOS(std::ostream& os) const override;

	SurgeonResearcher(const string name, const string specialty);

	SurgeonResearcher(Doctor&& other);

	virtual const char* type() const override { return "Surgeon Researcher"; }
};



#endif