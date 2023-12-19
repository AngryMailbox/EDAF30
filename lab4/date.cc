#include <ctime> // time and localtime
#include "date.h"
#include <iomanip>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date()
{
	time_t timer = time(0);			 // time in seconds since 1970-01-01
	tm *locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

void Date::next()
{
	day++;
	if (day > daysPerMonth[month - 1]) // Needs to be month -1
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
}

std::ostream &operator<<(std::ostream &os, const Date &d)
{
	os << d.year << "-" << d.month << "-" << d.day;
	return os;
}

std::istream &operator>>(std::istream &is, Date &d)
{
	char dash1, dash2;
	is >> d.year >> dash1 >> d.month >> dash2 >> d.day;

	if (is.fail() || dash1 != '-' || dash2 != '-')
	{
		is.setstate(std::ios_base::failbit);
	}

	return is;
}