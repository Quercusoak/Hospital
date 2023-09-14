#include "DateExceptions.h"

//------------------------------------------------//
DateExceptions::DateExceptions(unsigned short year, unsigned short month, unsigned short day) noexcept(false)
{
	if (year > CURRENT_YEAR || year < LOWEST_YEAR) //Expected card date to be current or previous date
	{
		throw "Year invalid. Expected year to be from " + std::to_string(LOWEST_YEAR) + " to " + std::to_string(CURRENT_YEAR) + ".";
	}

	if (month > NUM_OF_MONTHS || month < 1)
	{
		throw "Month invalid. Expected month to be between 1 to 12.";

	}

	
	if ((!isLeapYear(year) && month == FEBRUARY && day == FEBRUARY_LEAP))
	{

		throw "Entered Year is not a leap year.";

	}

	if (isLeapYear(year) && month == FEBRUARY)
	{
		if(day < 1 || day > FEBRUARY_LEAP)
			throw "Day invalid, in month " + std::to_string(month) + " there are " + std::to_string(monthDays[month - 1] + 1) + " days.";
	}
	else if (day < 1 || day > monthDays[month - 1])
	{
		throw "Day invalid, in month " + std::to_string(month) + " there are " + std::to_string(monthDays[month - 1]) + " days.";
		
	}
}
