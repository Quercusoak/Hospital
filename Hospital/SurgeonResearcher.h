#ifndef __SURGEON_RESEARCHER_H
#define __SURGEON_RESEARCHER_H

#include "Surgeon.h"
#include "Researcher.h"

class SurgeonResearcher : public Surgeon, public Researcher
{
public:
	SurgeonResearcher(const char* name, const char* specialty);

	SurgeonResearcher(Doctor&& other);

	virtual void toOS(std::ostream& os) const override;

	virtual const char* type() const override { return "Surgeon Researcher"; }
};



#endif