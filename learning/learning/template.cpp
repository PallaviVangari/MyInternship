#include<iostream>
using namespace std;

template<class T>
T add(float a, int b)
{
	return a + b;
}
template<class T>
T add(int a, float b)
{
	return a + b;
}
int main()
{
	int x = 10, y = 20;
	cout << add<int>(x, y);
	cout << add<char>(x, y);
	return 0;
}