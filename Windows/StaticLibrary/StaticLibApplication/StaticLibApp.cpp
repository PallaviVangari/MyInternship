#include "MathFuncs.h"
#include<iostream>
using namespace std;

int main()
{
	int num1 = 10, num2 = 5;
	cout << "Sum=" << Math::MyMathFuns::add(num1, num2) << endl;
	cout << "difference=" <<Math::MyMathFuns:: sub(num1, num2) << endl;
	cout << "product=" << Math::MyMathFuns::mul(num1, num2) << endl;
	cout << "quotient=" << Math::MyMathFuns::div(num1, num2) << endl;
	getchar();
	return 0;
}