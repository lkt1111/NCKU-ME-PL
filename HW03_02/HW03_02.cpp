/*	Project name :	HW03_02
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙						*/

/*	All rights reserved
		Plagiarism will be prosecuted	*/

#include <iostream>
#include <limits.h>
#include <float.h>
using namespace std;

int main()
{
	//Print bool, char, short, int, long, float, double, long double and string
	cout << "bool\t\t" << sizeof(bool) << "\t\t" << CHAR_MIN << "\t\t\t" << CHAR_MAX << endl;	//Size of bool = Size of char (defult)
	cout << "char\t\t" << sizeof(char) << "\t\t" << CHAR_MIN << "\t\t\t" << CHAR_MAX << endl;
	cout << "short\t\t" << sizeof(short) << "\t\t" << SHRT_MIN << "\t\t\t" << SHRT_MAX << endl;
	cout << "int\t\t" << sizeof(int) << "\t\t" << INT_MIN << "\t\t" << INT_MAX << endl;
	cout << "long\t\t" << sizeof(long) << "\t\t" << LONG_MIN << "\t\t" << LONG_MAX << endl;
	cout << "float\t\t" << sizeof(float) << "\t\t" << FLT_MIN << "\t\t" << FLT_MAX << endl;
	cout << "double\t\t" << sizeof(double) << "\t\t" << DBL_MIN << "\t\t" << DBL_MAX << endl;
	cout << "long double\t" << sizeof(long double) << "\t\t" << LDBL_MIN << "\t\t" << LDBL_MAX << endl;
	cout << "string\t\t" << sizeof(string);

	return 0;
}
