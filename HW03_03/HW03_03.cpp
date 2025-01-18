/*	Project name :	HW03_03
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙						*/

/*	All rights reserved
		Plagiarism will be prosecuted	*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//Declare PI
	const float PI = 3.1415926;

	//Input the data
	double x = 0;
	double theta = 0;
	cout << "Please input x: ";
	cin >> x;
	cout << "Please input theta: ";
	cin >> theta;

	//Transform into proper unit
	theta = theta * PI / 180;

	//Culculate and print the result
	cout << endl << setprecision(3) << fixed
		<< abs(3 * x - 9) +
		pow((pow(x, 12) + PI / atan(1. / theta)), 1. / 3) +
		exp(cos(theta)) * pow(sin(theta), 0.2) << endl;

	return 0;
}
