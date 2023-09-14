#ifndef __DATE_EXCEPTIONS_H
#define __DATE_EXCEPTIONS_H


#include <iostream>
#include <string>
#pragma warning(disable: 4996)

#define CURRENT_YEAR 2023
#define LOWEST_YEAR 1900
#define NUM_OF_MONTHS 12
#define FEBRUARY 2
#define FEBRUARY_LEAP 29


class DateExceptions : public std::exception 
{
private:
	
	static constexpr const int monthDays[] = 
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


public:
	DateExceptions(unsigned short year, unsigned short month, unsigned short day) noexcept(false);
	

	bool isLeapYear(unsigned short year) const
	{
		if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
			return true;
		else return false;
	}
};


#endif // !__MONTHS_EXCEPTIONS_H
