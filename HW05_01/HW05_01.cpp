/*	Project name :	HW05_01
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
	//Initialize the numbers
	double num[2] = { 9,3 };
	int input = 0;

	//Ask the user to input the value of x and check if the number is valid
	cout << "Please input the value of x :\t2 <= x <= 30" << endl;
	while (true) {
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "The input is not an integer\nPlease try again: ";
			continue;
		}
		if ((input >= 2) && (input <= 30))
			break;
		cout << "The number is invalid\nPlease try again: ";
	}

	//Print the results with for loop
	cout << setprecision(0) << fixed << "F[1]\t\t" << num[0] << endl;
	for (int i = 0; i < input - 1; i++) {
		cout << "F[" << i + 2 << "]\t\t" << num[(i + 1) % 2] << endl;	//If i is odd output the first number; if i isn't output the second one 
		num[i % 2] = 5 * num[i % 2] + num[(i + 1) % 2] - 3;				//Culculate and replace the value of the other number
	}

	//Print the result with while loop
	cout << endl << endl;
	num[0] = 9;
	num[1] = 3;
	{
		int i = 0;
		cout << setprecision(0) << fixed << "F[1]\t\t" << num[0] << endl;
		while (i < input - 1) {
			cout << "F[" << i + 2 << "]\t\t" << num[(i + 1) % 2] << endl;	//If i is odd output the first number; if i isn't output the second one 
			num[i % 2] = 5 * num[i % 2] + num[(i + 1) % 2] - 3;				//Culculate and replace the value of the other number
			i++;
		}
	}
	return 0;
}