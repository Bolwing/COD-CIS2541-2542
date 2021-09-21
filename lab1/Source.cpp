#include <iostream>
#include "quadraticExpression.h"

using namespace std;

void evaluateExpression(const quadraticExpression&);

int main()
{


	quadraticExpression q[6] = { quadraticExpression(2.1, 3, -7),
								 quadraticExpression(1.4, 3.9, +7),
								 quadraticExpression(-.75, 0, 0),
								 quadraticExpression(0, .3, -7),
								 quadraticExpression(0, 0, 4),
								 quadraticExpression() };


	for (int i = 0; i < 6; i++) {
		evaluateExpression(q[i]);
	}
	return EXIT_SUCCESS;
}

void evaluateExpression(const quadraticExpression& q)
{
	int errorsHandled = 0;
	
	cout << "f(-5) = " << q.evaluate(-5) << endl;
	cout << "f(0)  = " << q.evaluate(0) << endl;
	cout << "f(5)  = " << q.evaluate(5) << endl;

	if (q.getNumberOfRoots() == INFINITE_ROOTS)
		cout << "The Expression has Infinite Roots" << endl;
	else if (q.getNumberOfRoots() == ONE_ROOT)
		cout << "The Expression has One Root at x = " << q.getFirstRootLocation() << endl;
	else if (q.getNumberOfRoots() == TWO_ROOTS)
	{
		cout << "The Expression has First Root at x  = " << q.getFirstRootLocation() << endl;
		cout << "The Expression has Second Root at x = " << q.getSecondRootLocation() << endl;
	}
	else
		cout << "The Expression has No Roots" << endl;

	try {
		q.getFirstRoot();
	}
	catch (domain_error e) {
		errorsHandled++;
	}

	try {
		q.getSecondRoot();
	}
	catch (domain_error e) {
		errorsHandled++;
	}

	cout << "Errors Handled: " << errorsHandled << endl;

	cout << endl;
	cout << endl;
}

/*
OUTPUT


f(-5) = 30.5
f(0) = -7
f(5) = 60.5
The Expression has First Root at x = 1.24621
The Expression has Second Root at x = -2.67478
Errors Handled : 0


f(-5) = 22.5
f(0) = 7
f(5) = 61.5
The Expression has No Roots
Errors Handled : 0


f(-5) = -18.75
f(0) = 0
f(5) = -18.75
The Expression has One Root at x = -0
Errors Handled : 0


f(-5) = -8.5
f(0) = -7
f(5) = -5.5
The Expression has No Roots
Errors Handled : 0


f(-5) = 4
f(0) = 4
f(5) = 4
The Expression has No Roots
Errors Handled : 0


f(-5) = 0
f(0) = 0
f(5) = 0
The Expression has No Roots
Errors Handled : 0
*/