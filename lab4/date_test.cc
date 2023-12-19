#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"
#include <cassert>
#include <sstream>

using std::cout;
using std::endl;
using std::setfill;
using std::setw;

/*
 * Prints the date d in the format yyyy-mm-dd. You shall replace this
 * function with an overloaded operator<<, and add an overloaded operator>>.
 *
 */
void print(Date &d)
{
	cout << d;
	cin >> d;
}

void test1()
{

	Date testDate(2020, 10, 19);

	std::stringstream ss;
	ss << testDate;

	assert(ss.str() == "2020-10-19");
	cout << "Test 1 OK" << endl;
}

void test2()
{

	Date testDate(2020, 10, 11);

	std::stringstream ss;
	ss << "2020-10-11";
	ss >> testDate;

	assert(ss.str() == "2020-10-11");
	cout << "Test 2 OK" << endl;
}

void test3()
{

	Date testDate(2020, 10, 11);

	for (int i = 0; i < 31; i++)
	{
		testDate.next();
	}

	std::stringstream ss;
	ss << testDate;

	assert(ss.str() == "2020-11-11");
	cout << "Test 3 OK" << endl;
}

void test4()
{
	Date testDate(2020, 10, 11);

	std::stringstream ss;
	ss << "hej-10-32";
	ss >> testDate;

	assert(ss.rdstate() == std::ios_base::failbit);
	cout << "Test 4 OK" << endl;
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	cout << "All tests passed!" << endl;
}
