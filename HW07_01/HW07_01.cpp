#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;

// Function prototypes
double average(double *tests, int dataNum);
double standardDeviation(double *tests, int dataNum);
inline double normalize(double x, double max, double min);

// Struct to store student information
typedef struct student {
	int student_ID;
	double *test;	// Request 1
	double avg;		// Request 4
	double score;	// Request 6
} student;

int main()
{
	//Set random seed
	srand(static_cast<size_t>(time(NULL)));

	//Initialize and input the variables (request 1)
	int studentNum = 0, tests = 0;
	cout << "Please input the number of students: " << endl;
	while (true) {
		cin >> studentNum;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please input an integer:" << endl;
			continue;
		}
		if (studentNum <= 0) {
			cout << "The value must at least 1" << endl;
			continue;
		}
		break;
	}
	cout << "Please input the number of tests for each student: (at least 3 times)" << endl;
	while (true) {
		cin >> tests;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please input an integer:" << endl;
			continue;
		}
		else if (tests < 3) {
			cout << "The value must at least 3" << endl;
			continue;
		}
		break;
	}

	// Dynamically allocate memory for an array of students (request 1, 4, 6)
	student *data = new student[studentNum];
	for (int i = 0; i < studentNum; i++)
		data[i].test = new double[tests]; // Allocate memory for each student's test scores (request 1)

	// Assign student numbers starting from 1
	for (int i = 0; i < studentNum; i++)
		data[i].student_ID = i + 1;

	// Randomly generate test scores between 12.0 and 30.0 (request 2)
	for (int i = 0; i < studentNum; i++) {
		for (int j = 0; j < tests; j++) {
			data[i].test[j] = (rand() % 181) / 10.0 + 12;
		}
	}

	// Display test scores (request 3)
	cout << endl << "Score listing:" << endl << left << setw(10) << "No.";
	for (int i = 0; i < tests; i++) {
		cout << "test" << setw(6) << i + 1;
	}
	cout << endl << setprecision(1) << fixed;
	for (int i = 0; i < studentNum; i++) {
		cout << setw(10) << data[i].student_ID;
		for (int j = 0; j < tests; j++) {
			cout << setw(10) << data[i].test[j];
		}
		cout << endl;
	}

	// Calculate and store the average of each student (request 4)
	for (int i = 0; i < studentNum; i++) 
		data[i].avg = average(data[i].test, tests);

	// Sort (selection sort) students based on their average scores (request 5)
	for (int i = 0; i < studentNum - 1; i++) {
		double min = 31.;
		int index = 0;
		for (int j = i; j < studentNum; j++) {
			if (min > data[j].avg) {
				min = data[j].avg;
				index = j;
			}
		}
		student temp = data[index];
		data[index] = data[i];
		data[i] = temp;
	}

	// Calculate and store the deviation of each student (request 6)
	for (int i = 0; i < studentNum; i++)
		data[i].score = normalize(data[i].avg, data[studentNum - 1].avg, data[0].avg);

	// Display the ranking table (request 6)
	cout << endl << "Ranking:" << endl
		<< "Rank      No.       Average        Score" << endl;

	for (int i = 0; i < studentNum; i++) {
		cout << setw(10) << i + 1					// Rank
			<< setw(10) << data[i].student_ID			// Student ID
			<< data[i].avg << "\u00B1"							// Average
			<< standardDeviation(data[i].test, tests) << "  "	// Deviation
			<< setw(10) << right << data[i].score << endl << left;	// Score
	}

	// Free dynamically allocated memory (request 7)
	for (int i = 0; i < studentNum; i++) {
		delete[] data[i].test;
	}
	delete[] data;

	return 0;
}

// Function to calculate the average score
double average(double *tests, int dataNum) {
	double sum = 0;
	for (int i = 0; i < dataNum; i++)
		sum += tests[i];
	return sum / dataNum;
}

// Function to calculate the standard deviation of scores
double standardDeviation(double *tests, int dataNum) {
	double sqare_sum = 0;
	double avg = average(tests, dataNum);
	for (int i = 0; i < dataNum; i++)
		sqare_sum += pow((tests[i] - avg), 2);
	if (dataNum <= 1) return 0.0;
	return sqrt(sqare_sum / (dataNum - 1));
}

// Inline function to normalize scores
inline double normalize(double x, double max, double min) {
	return (max == min) ? 100 : (-40 / (max - min)) * (x - min) + 100;
}
