#ifndef __SURGEON_RESEARCHER_H
#define __SURGEON_RESEARCHER_H

#include "Surgeon.h"
#include "Researcher.h"

class SurgeonResearcher : public Surgeon, public Researcher
{
public:

	virtual void toOS(std::ostream& os) const override;

	virtual void fromOS(std::istream& in) override;


	SurgeonResearcher() = default;

	SurgeonResearcher(const string name, const string specialty);

	SurgeonResearcher(ifstream& in) { in >> *this; }

	SurgeonResearcher(Doctor&& other);

	virtual const string type() const override { return "Surgeon Researcher"; }
};



#endif