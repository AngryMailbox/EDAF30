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

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

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

ostream &operator<<(ostream &os, const Date &d)
{
	os << setw(4) << setfill('0') << d.getYear() << '-'
	   << setw(2) << setfill('0') << d.getMonth() << '-'
	   << setw(2) << setfill('0') << d.getDay();

	return os;
}

istream &operator>>(istream &is, Date &d)
{
	int year, month, day;

	char dash1, dash2;
	is >> year >> dash1 >> month >> dash2 >> day;

	if (is.good() && dash1 == '-' && dash2 == '-')
	{
		d = Date(year, month, day);
	}
	else
	{
		is.setstate(ios_base::failbit);
	}

	return is;
}