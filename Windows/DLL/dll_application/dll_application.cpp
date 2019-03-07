#include<windows.h>
#include"dll.h"
#include<iostream>
using namespace std;

int main()
{
	int num1 = 23, num2 = 12;
	cout << "sum=" << add(num1, num2);
	cout << "\ndifference=" << sub(num1, num2);
	getchar();
	return 0;
}