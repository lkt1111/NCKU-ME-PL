/*	Project name :	HW05_02
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙

	All rights reserved
	Plagiarism will be prosecuted	*/

#include <iostream>
using namespace std;

int main()
{
	//Print the result
	for (int num = 1; num <= 17; num += 2) {
		cout << "The height of hourglass : " << num << endl;
		cout << "==========================" << endl;
		for (int i = num / 2 + 1; i > 0; i--) {
			for (int j = 0; j < num / 2 + 1 - i; j++) {	//Adjust the range of j by comparing the value of current number(i)
				cout << ' ';
			}
			for (int j = 0; j < 2 * i - 1; j++) {	//Print the i in 2n - 1 times
				cout << i;
			}
			cout << endl;	//Put a '\n' if the number(i) changed
		}
		for (int i = 2; i <= num / 2 + 1; i++) {	//Reverse the operation above
			for (int j = 0; j < num / 2 + 1 - i; j++) {
				cout << ' ';
			}
			for (int j = 0; j < 2 * i - 1; j++) {
				cout << i;
			}
			cout << endl;
		}
		cout << endl << endl;	//Put 2 '\n' if num changed 
	}
	return 0;
}
