/*	Project name :	HW06_03
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙

	All rights reserved
	Plagiarism will be prosecuted	*/

#include <iostream>
using namespace std;

// Function to calculate the length of a character array
int stringlen(char(&str)[100]);

int main()
{
	char target_word[100] = { '\0' };
	cout << "Please input a word you want to find :" << endl;
	cin >> target_word;
	cin.ignore(); // Clear newline character

	int index[100] = { 0 }; // Initialize index array
	char article[100] = { '\0' };
	cout << "Please input the article :" << endl;
	cin.getline(article, 100);

	int k = 0; // Used to store found indices

	for (int i = 0; article[i] != '\0'; i++) {
		if (article[i] == ' ') continue; // Skip whitespace characters

		bool isSame = true;
		int index_buf = i + 1; // Save the start position of the word
		int x = 0; // Reset x for each new word comparison

		// Compare characters in target_word with article
		for (; article[i] != ' ' && article[i] != '\0'; x++, i++) {
			if (tolower(article[i]) != tolower(target_word[x])) {
				isSame = false;
			}
		}

		// Ensure full match of target_word and word boundary
		if (isSame && target_word[x] == '\0') {
			index[k] = index_buf;
			k++;
		}
	}

	// Output all matching indices
	if (index[0] != 0) { // If matches are found
		for (int i = 0; index[i] != 0; i++) {
			cout << index[i] << endl;
		}
	}
	else {
		cout << -1 << endl; // If no match is found, output -1
	}

	return 0;
}

// Function to calculate the length of a character array
int stringlen(char(&str)[100]) {
	int length = 0;
	for (; str[length] != '\0'; length++); // Count characters until null character is reached
	return length;
}
