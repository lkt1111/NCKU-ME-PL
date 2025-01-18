/*	Project name :	HW03_04
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙						*/

/*	All rights reserved
		Plagiarism will be prosecuted	*/

#include <iostream>
#include <ctime>
using namespace std;


//Declare golbal total
int total = 100;

int main()
{	
	//Set ramdom seed
	srand(static_cast<unsigned int>(time(0)));

	//Declare total in main
	int total = 20;
	{
		//Declare total in inner block
		int total = 10;
		total += rand() % 50 + 1;	//Initialize total in inner block
		cout << "total in inner block:\t" << total << endl;
		::total *= -10;	//Motify global total 
	}
	
	//Print the result
	cout << "total in main:\t" << total << endl
		<< "global total:\t" << ::total << endl;

	return 0;
}
