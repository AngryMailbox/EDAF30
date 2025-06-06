#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
public:
	Date();								// today's date
	Date(int year, int month, int day); // yyyy-mm-dd
	int getYear() const;				// get the year
	int getMonth() const;				// get the month
	int getDay() const;					// get the day
	void next();						// advance to next day

	// Define the operator<< for output
	friend ostream &operator<<(ostream &os, const Date &d);

	// Define the operator>> for input
	friend istream &operator>>(istream &is, Date &d);

private:
	int year;					 // the year (four digits)
	int month;					 // the month (1-12)
	int day;					 // the day (1-..)
	static int daysPerMonth[12]; // number of days in each month
};

#endif
