// File: Driver.cpp
// Note: Used to test our date class with overloaded functions

#include <iostream>
#include "d_date.h"

using namespace std;

void main (void)
{
	date date1;
	date date2;

	cout << "Enter date1 and date2:" << endl;

	while (cin >> date1 >> date2)
	{
		cout << "Printing date1 and date2" << endl;
		cout << date1 << endl << date2 << endl;

		if (date1 == date2) 
			cout << date1 << " is equal to " << date2 << endl;

		if (date1 != date2) 
			cout << date1 << " is not equal to " << date2 << endl;

		if (date1 < date2) 
			cout << date1 << " is less than " << date2 << endl;

		if (date1 > date2) 
			cout << date1 << " is greater than " << date2 << endl;

		++date1;
		++date2;

		cout << "Increment of date1: " << date1 << endl;
		cout << "Increment of date2: " << date2 << endl;

		cout << endl << "---End of Run---" << endl << endl;

		cout << "Enter date1 and date2:" << endl;
	}

}

