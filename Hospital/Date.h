#ifndef __DATE_H
#define __DATE_H

#include <fstream>
#include "DateExceptions.h"

class Date
{
private:
	unsigned short year, month, day;


public:
	Date();
	Date(unsigned short year, unsigned short month, unsigned short day) noexcept(false);
	Date(ifstream& in) { in >> *this; }

	void setYear(unsigned short year);
	void setMonth(unsigned short month);
	void setDay(unsigned short day); 

	unsigned short getYear() const;
	unsigned short getMonth() const;
	unsigned short getDay() const;

	friend std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		if (typeid(os) == typeid(ofstream))
			os << date.getDay() << " " << date.getMonth() << " " << date.getYear();
		else
			os << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
		return os;
	}

	friend std::istream& operator>>(std::istream& in, Date& date)
	{
		in >> date.day >> date.month >> date.year;
		return in;
	}

};

#endif __DATE_H