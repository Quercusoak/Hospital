#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable: 4996)

class Date
{
private:
	unsigned short year, month, day;

public:
	Date();
	Date(unsigned short year, unsigned short month, unsigned short day);

	void setYear(unsigned short year);
	void setMonth(unsigned short month);
	void setDay(unsigned short day); 

	unsigned short getYear() const;
	unsigned short getMonth() const;
	unsigned short getDay() const;

	friend std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		os << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
		return os;
	}
};

#endif __DATE_H