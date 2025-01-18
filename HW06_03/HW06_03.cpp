/*	Project name :	HW06_03 (Using KMP algorithm)
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙

	All rights reserved
	Plagiarism will be prosecuted	*/

int stringlen(char(&str)[1000]);

#include <iostream>
using namespace std;

int main()
{
	// Sample input: text string (str) and the pattern to search for (pattern)
	char str[1000] = { 0 };  // Main string to search in
	char pattern[1000] = { 0 };           // Pattern we want to find

	cout << "Please input the article :" << endl;
	cin.getline(str, 1000);
	cout << "Please input the pattern you want to find :" << endl;
	cin.getline(pattern, 1000);

	// Array to store the partial match table (also known as the 'next' table)
	int next[100] = { 0 };

	// Build the 'next' table (partial match table) for the pattern
	next[0] = 0;  // The first position in the 'next' table is always 0
	for (int i = 1; i < stringlen(pattern); i++) {
		// If the current character matches the previous match, extend the match length
		if (pattern[next[i - 1]] == pattern[i]) {
			next[i] = next[i - 1] + 1;
		}
		else {
			// If the previous match length is 0, set the current match length to 0
			if (next[i - 1] == 0) {
				next[i] = 0;
			}
			else {
				// Otherwise, fall back to a shorter prefix that might match
				if (pattern[next[next[i - 1] - 1]] == pattern[i]) {
					next[i] = next[next[i - 1] - 1] + 1;
				}
				else {
					next[i] = 0;
				}
			}
		}
	}

	// Calculate the lengths of the text string and the pattern
	int len_str = stringlen(str);
	int len_pat = stringlen(pattern);
	bool flag = true;

	// Initialize pointers for the text (strP) and the pattern (patternP)
	int strP = 0, patternP = 0;

	// Begin searching for the pattern in the text
	while (strP < len_str)
	{
		// If characters match, move both pointers forward
		if (str[strP] == pattern[patternP]) {
			strP++;  // Move the text pointer forward
			patternP++;  // Move the pattern pointer forward
		}
		else {
			// If there's a mismatch and patternP is not at the start (0), use the 'next' table to jump to the next potential match
			if (patternP != 0) {
				patternP = next[patternP - 1];  // Shift patternP based on the 'next' table
			}
			else {
				// If patternP is at the start (0), move strP forward to continue searching
				strP++;
			}
		}

		// If the entire pattern has been matched (patternP == len_pat), output the match index
		if (patternP == len_pat) {
			flag = false;
			cout << "Index: " << strP - patternP << endl;  // Output the starting index of the match
			patternP = next[patternP - 1];  // Use the 'next' table to continue searching for other possible matches
		}
	}

	if (flag) cout << -1;

	return 0;
}

int stringlen(char(&str)[1000]) {
	int length = 0;
	for (; str[length] != '\0'; length++);
	return length;
}

