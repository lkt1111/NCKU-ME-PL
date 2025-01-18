/*	Project name :	HW06_01
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙

	All rights reserved
	Plagiarism will be prosecuted	*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Initialize the month and prompt the user to input a value
	int month = 0;
	cout << "Please input the month (1 to 12)" << endl;
	while (true) {
		cin >> month;
		if (cin.fail()) { // Check if input is not an integer
			cin.clear(); // Clear the error flag
			cin.ignore(1000, '\n'); // Ignore invalid input
			cout << "The input is not an integer\nPlease try again: ";
			continue;
		}
		if (month > 12 || month < 1) { // Ensure month is between 1 and 12
			cout << "Please input an integer between 1 and 12 :" << endl;
			continue;
		}
		break; // Exit loop if valid input
	}
	cout << "// SUN=0 MON=1 TUE=2 WED=3 THU=4 FRI=5 SAT=6" << endl;
	cout << month << "/1 is ";
	int prefix = 0;
	while (true) {
		cin >> prefix;
		if (cin.fail()) { // Check if input is not an integer
			cin.clear(); // Clear the error flag
			cin.ignore(1000, '\n'); // Ignore invalid input
			cout << "The input is not an integer\nPlease try again: ";
			continue;
		}
		if (prefix > 6 || prefix < 0) { // Ensure month is between 1 and 12
			cout << "Please input an integer between 0 and 6 :" << endl;
			continue;
		}
		break; // Exit loop if valid input
	}
	
	cout << "=======================================" << endl;
	cout << "SUN   MON   TUE   WED   THU   FRI   SAT" << endl << left;

	// Print initial empty spaces for the first week
	int counter = 0;
	for (int i = 0; i < prefix; i++) {
		cout << "      ";
		counter++;
	}

	// Ensure the output consistency of month 1
	bool isprefix0 = counter == 0;

	// Print days of the month, adjusting for line breaks at the end of each week
	for (int i = 1; i <= (month % 2 == 0 ? 30 : 31); i++) {
		if (counter % 7 == 0 && !isprefix0) { // End of line in 7 days
			cout << endl;
			counter = 0;
		}
		cout << setw(6) << i; // Print day with width 6
		counter++;
		isprefix0 = false;
	}
	cout << endl << "=======================================" << endl;

	return 0;
}