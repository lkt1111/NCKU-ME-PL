/*	Project name :	HW04_02
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙

	All rights reserved
	Plagiarism will be prosecuted	*/

#include <iostream>
using namespace std;

int main()
{
	//Initialize and input the value of year, month, and date 
	int year = 0;
	int month = 0;
	int date = 0;
	cout << "Please input the year: ";
	cin >> year;
	cout << "Please input the month: ";
	cin >> month;
	cout << "Please input the date: ";
	cin >> date;
	
	switch (month)
	{
	//Determin the result when the month is a long one
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
		if ((date >= 0) && (date <= 31)) {
			cout << "Existing day" << endl;
		}
		else {
			cout << "Non-existing day" << endl;
		}
		break;

	//Determin the result when the month is a short one
	case 4: case 6: case 9: case 11:
		if ((date >= 0) && (date <= 30)) {
			cout << "Existing day" << endl;
		}
		else {
			cout << "Non-existing day" << endl;
		}
		break;

	//Determin which kind of month 2 according to the given conditions and output the result
	case 2:
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
			if ((date >= 0) && (date <= 29)) {
				cout << "Existing day" << endl;
			}
			else {
				cout << "Non-existing day" << endl;
			}
		}
		else {
			if ((date >= 0) && (date <= 28)) {
				cout << "Existing day" << endl;
			}
			else {
				cout << "Non-existing day" << endl;
			}
		}
		break;

	//Outputing the result when the inputed month isn't match above conditions
	default:
		cout << "Non-existing day" << endl;
	}
	return 0;
}
