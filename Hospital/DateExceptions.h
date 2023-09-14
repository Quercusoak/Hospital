#ifndef __DATE_EXCEPTIONS_H
#define __DATE_EXCEPTIONS_H

#include <map>
#include "Date.h"
#pragma warning(disable: 4996)


class DateExceptions : public std::exception 
{
private:
	enum class Months {};

public:
	DateExceptions() {}
};


#endif // !__MONTHS_EXCEPTIONS_H
