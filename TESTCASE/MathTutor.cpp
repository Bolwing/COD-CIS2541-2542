// MathTutor.cpp : MathTutor is a program where the user is able to pick a problem type and is given problems until they choose to close the program :
// Kenneth Segovia June 19 2018
//

#include <iostream>
#include <random>
#include <string>
#include <ios>
#include <time.h>

using namespace std;

int main()
{
	srand(time(0));
	
	int isDone = 0;


	while (isDone == 0) {

		int problemType = 0;
		int soln;
		int rand1 = rand() % 1000 + 500;
		int rand2 = rand() % 1000 + 500;
		int randAddSoln = rand1 + rand2;
		int randSubSoln = rand1 - rand2;
		int randMulSoln = rand1 * rand2;
		int randDivSoln = rand1 / rand2;
		
		string ans;


		cout << "Select problem type" << endl;
		cout << "1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Integer Division" << endl;

		cin >> problemType;

		cout << "---------------------" << endl;

		isDone = 1;

		if (problemType != 1 && problemType != 2 && problemType != 3 && problemType != 4) {
			problemType = 0;
		}
		else {
			problemType = problemType;
		}

		switch (problemType) {
		case 0:
			cout << "INVALID OPERATION" << endl;
			isDone = 0;
			break;

		case 1: //ADDITION//
			cout.width(to_string(rand1).length() + 2);
			cout << rand1 << right << '\n';
			cout.width(to_string(rand2).length() - 2);
			cout << "+ " << rand2 << right << '\n';
			cout << "--------------" << endl;
			cin >> soln;
			if (soln == randAddSoln) {
				cout << "Correct" << endl;
				cout << "Do you want to continue? Y/N" << endl;
				cin >> ans;
				if (ans == "Y") {
					isDone = 0;
				}
				else {
					isDone = 1;
				}
			}
			else {
				cout << "Incorrect! The correct answer was " << randAddSoln << endl;
				cout << "Do you want to continue? Y/N" << endl;
				cin >> ans;
				if (ans == "Y") {
					isDone = 0;
				}
				else {
					isDone = 1;
				}
			}
			break;



		case 2: //SUBTRACTION//
			cout.width(to_string(rand1).length() + 2);
			cout << rand1 << right << '\n';
			cout.width(to_string(rand2).length() - 2);
			cout << "- " << rand2 << endl;
			cout << "--------------" << endl;
			cin >> soln;
			if (soln == randSubSoln) {
				cout << "Correct" << endl;
				cout << "Do you want to continue? Y/N" << endl;
				cin >> ans;
				if (ans == "Y") {
					isDone = 0;
				}
				else {
					isDone = 1;
				}
			}
			else {
				cout << "Incorrect! The correct answer was " << randSubSoln << endl;
				cout << "Do you want to continue? Y/N" << endl;
				cin >> ans;
				if (ans == "Y") {
					isDone = 0;
				}
				else {
					isDone = 1;
				}
			}
			break;

		case 3: //MULTIPLICATION//
			cout.width(to_string(rand1).length() + 2);
			cout << rand1 << right << '\n';
			cout.width(to_string(rand2).length() - 2);
			cout << "* " << rand2 << endl;
			cout << "--------------" << endl;
			cin >> soln;
			if (soln == randMulSoln) {
				cout << "Correct" << endl;
				cout << "Do you want to continue? Y/N" << endl;
				cin >> ans;
				if (ans == "Y") {
					isDone = 0;
				}
				else {
					isDone = 1;
				}
			}
			else {
				cout << "Incorrect! The correct answer was " << randMulSoln << endl;
				cout << "Do you want to continue? Y/N" << endl;
				cin >> ans;
				if (ans == "Y") {
					isDone = 0;
				}
				else {
					isDone = 1;
				}
			}
			break;

		case 4://DIVISION//
			cout.width(to_string(rand1).length() + 2);
			cout << rand1 << right << '\n';
			cout.width(to_string(rand2).length() - 2);
			cout << "/ " << rand2 << endl;
			cout << "--------------" << endl;
			cin >> soln;
			if (soln == randDivSoln) {
				cout << "Correct" << endl;
				cout << "Do you want to continue? Y/N" << endl;
				cin >> ans;
				if (ans == "Y") {
					isDone = 0;
				}
				else {
					isDone = 1;
				}
			}
			else {
				cout << "Incorrect! The correct answer was " << randDivSoln << endl;
				cout << "Do you want to continue? Y/N" << endl;
				cin >> ans;
				if (ans == "Y") {
					isDone = 0;
				}
				else {
					isDone = 1;
				}
			}

			break;


		}
	}
	return 0;
}

/* SAMPLE OUTPUT

Select problem type
1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Division
!USER INPUT 1
1200
+ 1500
-----
!USER INPUT 2700
Correct
Do you want to continue? Y/N
!USER INPUT Y
Select problem type
1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Division
!USER INPUT 2
1200
- 1500
-----
!USER INPUT -500
Incorrect! The correct answer was -300
Do you want to continue? Y/N
!USER INPUT Y
Select problem type
1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Division
!USER INPUT 3
500
* 500
-----
!USER INPUT 250000
Correct
Do you want to continue? Y/N
!USER INPUT Y
Select problem type
1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Division
!USER INPUT 4
800
/ 200
-----
!USER INPUT 4
Correct
Do you want to continue? Y/N
!USER INPUT Y
Select problem type
1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Division
!USER INPUT 5
INVALID OPERATION
Select problem type
1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Division
!USER INPUT 1
200
+ 200
!USER INPUT 400
Correct
Do you want to continue? Y/N

!USER INPUT N
!PROGRAM CLOSE
*/