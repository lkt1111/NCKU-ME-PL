/*	Project name :	HW06_02
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙

	All rights reserved
	Plagiarism will be prosecuted	*/

#include <iostream>
using namespace std;

// Function to calculate the length of a character array
int stringlen(char(&str)[1000]);

// Function to check if a character array is a palindrome
bool isPalindrome(char(&str)[1000]);

int main()
{
	char str[1000] = { 0 }; // Initialize the input string array
	cout << "Please input the string :" << endl;
	cin.getline(str, 1000);
	char subStr[1000] = { '\0' }; // Initialize an empty array to hold the processed string
	for (int i = 0, j = 0; i < stringlen(str); i++) {
		if (isalpha(str[i])) { // Check if the character is alphabetic, if it is, convert to lowercase and store in 'subStr'
			subStr[j] = tolower(str[i]);
			j++;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			subStr[j] = str[i];
			j++;
		}
	}

	cout << str << " is" << (isPalindrome(subStr) ? "" : " not") << " Palindrome";
	
	return 0;
}

// Function to determine the length of a character array
int stringlen(char(&str)[1000]) {
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++, length++); // Count characters until null character is reached
	return length;
}

// Function to check if a character array is a palindrome
bool isPalindrome(char(&str)[1000]) {
	for (int i = 0; i < stringlen(str) / 2; i++) { // Loop through half of the array
		if (str[i] != str[stringlen(str) - 1 - i]) return false; // Check if characters from both ends match, if any two elements isn't match, retuen false 
	}
	return true;
}
