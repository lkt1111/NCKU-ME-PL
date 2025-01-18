/*	Project name :	HW04_01
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙			

	All rights reserved
	Plagiarism will be prosecuted	*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{	
	//Ask the user to input the value of x
	cout << "Please input a floating-point number: " << endl << setprecision(4) << fixed;
	float x = 0;
	cin >> x;

	//Output the result according to the given function
	if (x < 0) {
		cout << "sin(x) = " << sin(x) << endl;
	}
	else if ((x >= 0) && (x < 1)) {
		cout << "x = " << x << endl;
	}
	else {
		cout << "exp(x - 1) = " << exp(x - 1) << endl;
	}

	return 0;
}

