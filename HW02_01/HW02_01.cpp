// E14131011 版權所有 抄襲必究

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const float PI = 3.14159;
	float rad = 0.;
	srand(static_cast<unsigned int>(time(0)));			// 賦予亂數種子
	rad = (rand() % 100 + 1) / 10.;						// 0 < 取值 < 10
	cout << "radius:" << rad << setprecision(1) << endl;
	cout << fixed << setprecision(4);					//設定小數輸出格式
	cout << "surface area:" << 4. * PI * rad * rad << endl;
	cout << "volume:" << 4. / 3. * PI * rad * rad * rad << endl;

	return 0;
}