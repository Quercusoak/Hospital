#ifndef __MONTHS_H
#define __MONTHS_H

#include <iostream>
#include <map>
#pragma warning(disable: 4996)


class Months
{
public:
	static Months* getInstance();
	~Months() = default;


private:
	std::map<int, int> months;

	Months() {
		months[1] = 31;
	}
	Months(const Months&) = delete;
	const Months& operator=(const Months&) = delete;

	static Months theMonths;
};

#endif // !__MONTHS_H
