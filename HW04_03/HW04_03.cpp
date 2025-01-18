/*	Project name :	HW04_03
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙

	All rights reserved
	Plagiarism will be prosecuted	*/

#include <iostream>
#include <cmath>
using namespace std;

//Declare the Bubble Sort function
void bubbleSort(double *lengths, int layer);

int main()
{
	//Initialize and input the values of lengths
	double lengths[3] = { 0 };
	cout << "Please input three lengths of a triangle: " << endl;
	cin >> lengths[0];
	cin >> lengths[1];
	cin >> lengths[2];

	//Sort the double array form big to small
	bubbleSort(lengths, 3);

	//If the smallest value is negative, the input is invalid
	if (lengths[2] >= 0) {

		//Any added value of any two lengths is greater than or equal to the other length 
		if (lengths[0] >= lengths[1] + lengths[2]) {
			cout << "Not a Triangle" << endl;
		}

		//If a is the maximun and it is right triangle, a^2 = b^2 + c^2
		//Due to floating-point culculating errors, we must provide a threshold value
		else if (fabs((lengths[0] * lengths[0]) - (lengths[1] * lengths[1] + lengths[2] * lengths[2])) <= 1e-6){
			cout << "Right Triangle" << endl;
		}

		//If a is the maximun and it is acute triangle, a^2 < b^2 + c^2
		else if ((lengths[0] * lengths[0]) < (lengths[1] * lengths[1] + lengths[2] * lengths[2])) {
			cout << "Acute Triangle" << endl;
		}

		//If a is the maximun and it is obtuse triangle, a^2 > b^2 + c^2
		else {
			cout << "Obtuse Triangle" << endl;
		}
	}
	else {
		cout << "Negative value is invalid" << endl;
	}

	return 0;
}

void bubbleSort(double *lengths, int layer) {
	while (true) {
		//If any value has been changed, the loop continues
		bool flag = false;

		//Start from lengths[1] to lengths[layer], and move the smaller elements to the right
		for (int i = 1; i < layer; i++)
		{
			if (lengths[i - 1] < lengths[i]) {
				float buf = 0;
				buf = lengths[i];
				lengths[i] = lengths[i - 1];
				lengths[i - 1] = buf;
				flag = true;
			}
		}
		if (!flag) break;
	}
	return;
}