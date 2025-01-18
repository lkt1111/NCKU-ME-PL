// E14131011 版權所有 抄襲必究

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int factorial(int tmp);

int main()
{
	const float PI = 3.14159;
	const float E = 2.71828;
	cout << "n" << setw(10) << "exact" << setw(10) << "approx" << setw(10) << "error" << endl;
	for (int i = 1; i <= 5; ++i)
	{
		float approx = sqrt(2 * PI * i) * pow((i / E), i);	//代入史特靈公式計算
		cout << fixed << setprecision(4);
		cout << i << setw(10) << factorial(i) << setw(10) << approx << setw(10) << (approx - factorial(i)) / factorial(i) << endl;
	}

	return 0;
}

int factorial(int tmp) {	//定義階層函式
	int num = 1;
	for (int i = 1; i <= tmp; i++) {
		num *= i;
	}
	return num;
}