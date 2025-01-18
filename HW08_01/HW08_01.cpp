/*	Project name :	HW08_01
	Student number:	E14131011
	Author:			Kuan-Ting Liu
	Class: 乙

	All rights reserved
	Plagiarism will be prosecuted	*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

//Function prototypes
inline double random(double, double);
double** createMatrix(int, int);
inline double* createDoubleArray(int);
inline int* createIntArray(int);
void fillScore(double**, int, int);
void showScore(const double* const*, int, int);
void calculateStats(const double* const*, double*, double*, int, int);
void sortByAverage(const double*, int*, int);
void assignScore(const double*, int*, double*, int);
void showSortedScore(const int*, const double*, const double*, const double*, int, int);
inline void release(double**, int);
inline void release(double*);
inline void release(int*);

int main()
{
	//Set the random seed and initialize the console output
	srand(static_cast<size_t>(time(NULL)));
	cout << setprecision(1) << fixed;

	//Ask the user to input the number of students and tests
	int numStudents = 0, numTests = 0;
	cout << "Enter the number of students: ";
	while (true) {
		cin >> numStudents;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please input an integer:" << endl;
			continue;
		}
		if (numStudents <= 0) {
			cout << "The value must at least 1" << endl;
			continue;
		}
		break;
	}
	cout << "Enter the number of tests: ";
	while (true) {
		cin >> numTests;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please input an integer:" << endl;
			continue;
		}
		else if (numTests < 3) {
			cout << "The value must at least 3" << endl;
			continue;
		}
		break;
	}

	//Allcolate, fill and show the scores of each students (values between 12.0 and 30.0)
	double** score = createMatrix(numStudents, numTests);
	fillScore(score, numStudents, numTests);
	showScore(score, numStudents, numTests);

	//Allcolate the one dimensional arrays (each index of array metapher the number of each students)
	double* mean = createDoubleArray(numStudents);
	double* stddev = createDoubleArray(numStudents);
	double* grade = createDoubleArray(numStudents);
	int* rank = createIntArray(numStudents);

	//Calculate and store datas in arrays
	calculateStats(score, mean, stddev, numStudents, numTests);
	sortByAverage(mean, rank, numStudents);
	assignScore(mean, rank, grade, numStudents);
	showSortedScore(rank, mean, stddev, grade, numStudents, numTests);

	//Release the allcolated memories
	release(score, numStudents);
	release(mean);
	release(stddev);
	release(grade);
	release(rank);

	return 0;
}

//Function declaraions
inline double random(double lower, double upper) {
	return (static_cast<double>(rand()) / RAND_MAX)*(upper - lower) + lower;
}
double** createMatrix(int numStudents, int numTests) {
	double **matrix = new double*[numStudents];
	for (int i = 0; i < numStudents; i++)
		matrix[i] = new double[numTests];
	return matrix;
}
inline double* createDoubleArray(int numStudents) {
	return new double[numStudents];
}
inline int* createIntArray(int numStudents) {
	return new int[numStudents];
}
void fillScore(double** score, int numStudents, int numTests) {
	for (int i = 0; i < numStudents; i++)
		for (int j = 0; j < numTests; j++)
			score[i][j] = random(12., 30.);
	return;
}
void showScore(const double* const* score, int numStudents, int numTests) {
	cout << endl << left << "Scores listing:" << endl
		<< "No.     ";
	for (int i = 0; i < numTests; i++)
		cout << "test" << i + 1 << "   ";
	cout << endl;
	for (int i = 0; i < numStudents; i++) {
		cout << setw(8) << i + 1;
		for (int j = 0; j < numTests; j++) {
			cout << setw(8) << score[i][j];
		}
		cout << endl;
	}
	cout << right << endl;
	return;
}
void calculateStats(const double* const* score, double* mean, double* stddev, int numStudents, int numTests) {
	for (int i = 0; i < numStudents; i++) {
		double sum = 0;
		for (int j = 0; j < numTests; j++) {
			sum += score[i][j];
		}
		mean[i] = sum / numTests;
	}
	for (int i = 0; i < numStudents; i++) {
		double sqare_sum = 0;
		for (int j = 0; j < numTests; j++)
			sqare_sum += pow((score[i][j] - mean[i]), 2);
		stddev[i] = sqrt(sqare_sum / (numTests - 1));
	}
	return;
}
void sortByAverage(const double* mean, int* rank, int numStudents) {
	double* tmpMean = createDoubleArray(numStudents);
	for (int i = 0; i < numStudents; i++)
		tmpMean[i] = mean[i];
	for (int i = 0; i < numStudents - 1; i++) {
		double min = 31.;
		int index = 0;
		for (int j = i; j < numStudents; j++) {
			if (min > tmpMean[j]) {
				min = tmpMean[j];
				index = j;
			}
		}
		double temp = tmpMean[index];
		tmpMean[index] = tmpMean[i];
		tmpMean[i] = temp;
	}
	for (int i = 0; i < numStudents; i++) {
		for (int j = 0; j < numStudents; j++) {
			if (tmpMean[i] == mean[j]) rank[j] = i + 1;
		}
	}
	release(tmpMean);
	return;
}
void assignScore(const double* mean, int* rank, double* grade, int numStudents) {
	double max = 11;
	double min = 31;
	for (int i = 0; i < numStudents; i++) {
		if (max < mean[i]) max = mean[i];
		if (min > mean[i]) min = mean[i];
	}
	for (int i = 0; i < numStudents; i++) {
		grade[i] = (max == min) ? 100 : (-40 / (max - min)) * (mean[i] - min) + 100;
	}
	return;
}
void showSortedScore(const int* rank, const double* mean, const double* stddev, const double* grade, int numStudents, int numTests) {
	cout << "Ranking: " << endl << left
		<< "Rank    No.     Average          Score" << endl;
	for (int i = 1; i <= numStudents; i++) {
		int index = 0;
		for (int j = 0; j < numStudents; j++) {
			if (rank[j] == i) {
				index = j;
				break;
			}
		}
		cout << setw(8) << i << setw(8) << index + 1 << mean[index] << "\u00B1" << stddev[index] << "         " << grade[index] << endl;
	}
	cout << right;
}
inline void release(double** score, int numStudents) {
	for (int i = 0; i < numStudents; i++)
		delete[] score[i];
	delete[] score;
}
inline void release(double* ptr) {
	delete[] ptr;
}
inline void release(int* ptr) {
	delete[] ptr;
}

