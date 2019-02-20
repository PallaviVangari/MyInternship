#include<iostream>
using namespace std;

void swapbyvalue(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "After swapping: Values of variables in function=" << a << " " << b;
}
void swapbyreference(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "After swapping: Values of variables in function=" << a << " " << b;
}
int main()
{
	int a, b;
	int ch;
	cout << "Enter two numbers:";
	cin >> a >> b;
	cout << "Enter 1 for swap by value 2 for swap by reference";
	cin >> ch;
	switch (ch)
	{
	case 1:cout << "NUmbers before swap:" << a << " " << b<<endl;
		swapbyvalue(a, b);
		cout << "NUmbers after swap in main" << a << " " << b << endl;
		break;
	case 2:
		cout << "NUmbers before swap:" << a << " " << b << endl;
		swapbyreference(a, b);
		cout << "NUmbers after swap in main" << a << " " << b << endl;
		break;
	default:cout << "Invalid choice";
	}

}