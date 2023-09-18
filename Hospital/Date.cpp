#include "Date.h"

Date::Date() 
{
	year = month = day = 0;
}

Date::Date(unsigned short year, unsigned short month, unsigned short day) noexcept(false)
{
	DateExceptions check(year, month, day);

	setYear(year);
	setMonth(month);
	setDay(day);
}

void Date::setYear(unsigned short year)
{
	this->year = year;
}

void Date::setMonth(unsigned short month)
{
	this->month = month;
}

void Date::setDay(unsigned short day)
{
	this->day = day;
}

unsigned short  Date::getYear() const
{
	return year;
}

unsigned short  Date::getMonth() const
{
	return month;
}

unsigned short  Date::getDay() const
{
	return day;
}