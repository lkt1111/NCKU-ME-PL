/*	Project name :	HW03_01
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙						*/

/*	All rights reserved
		Plagiarism will be prosecuted	*/

#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

//Declare a funtion and define it at the end of the code
void print_int_Binary(int num);

int main()
{
	//Set random seed
	srand(static_cast<unsigned int>(time(0)));

	//Initialize numbers
	int number1 = rand() % 61 + 65;
	int number2 = rand() % 61 + 65;

	//Print the two numbers
	cout << "Two random numbers " << endl
		<< "Number1: " << number1 << endl
		<< "Number2: " << number2 << endl << endl;

	/*	A	B	&			A	B	|			A	B	^			A	~
	|	0	0	0	|	|	0	0	0	|	|	0	0	0	|	|	0	1	|
	|	0	1	0	|	|	0	1	1	|	|	0	1	1	|	|	0	1	|
	|	1	0	0	|	|	1	0	1	|	|	1	0	1	|	|	1	0	|
	|	1	1	1	|	|	1	1	1	|	|	1	1	0	|	|	1	0	|
																			*/
	//Culculating the numbers using AND 
	cout << "AND(&)" << endl;
	cout << "Number1:\t\t";
	print_int_Binary(number1);
	cout << "Number2:\t\t";
	print_int_Binary(number2);
	cout << "Number1 & Number2:\t";
	print_int_Binary(number1 & number2);
	cout << "\t\t\t= " << (number1 & number2) << endl;

	//Culculating the numbers using OR
	cout << "OR (|)" << endl;
	cout << "Number1:\t\t";
	print_int_Binary(number1);
	cout << "Number2:\t\t";
	print_int_Binary(number2);
	cout << "Number1 | Number2:\t";
	print_int_Binary(number1 | number2);
	cout << "\t\t\t= " << (number1 | number2) << endl;

	//Culculating the numbers using XOR
	cout << "XOR(^)" << endl;
	cout << "Number1:\t\t";
	print_int_Binary(number1);
	cout << "Number2:\t\t";
	print_int_Binary(number2);
	cout << "Number1 ^ Number2:\t";
	print_int_Binary(number1 ^ number2);
	cout << "\t\t\t= " << (number1 ^ number2) << endl;

	//Culculating number1 using NOT
	cout << "NOT(~)" << endl;
	cout << "Number1:\t\t";
	print_int_Binary(number1);
	cout << "~Number1:\t\t";
	print_int_Binary(~number1);
	cout << "\t\t\t= " << ~number1 << endl;

	//Culculating number2 using NOT
	cout << "Number2:\t\t";
	print_int_Binary(number2);
	cout << "~Number1:\t\t";
	print_int_Binary(~number2);
	cout << "\t\t\t= " << ~number2 << endl;
	cout << endl;

	return 0;
}


//Define a funtion to print binary
void print_int_Binary(int num) {
	int counter = 0;
	do {
		cout << ((num & (unsigned int)2147483648) >> 31);	//Unsigned int "2147483648" is "10000000000000000000000000000000" in binary
		num <<= 1;	//Put each '1' and '0' left in binary 
		counter++;
	} while (num);	//If number is not 0, the condition is true 
	for (int i = 0; i < 32 - counter; i++)	//Print the '0' behind the last '1' of target binary
		cout << '0';
	cout << endl;
}
