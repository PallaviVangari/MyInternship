#include<iostream>
using namespace std;

class Arith
{
	int a;
	int b;
public:
	Arith(int x, int y)
	{
		a = x;
		b = y;
	}
	inline int add()
	{
		return a + b;
	}
	inline int sub()
	{
		return a - b;
	}
	inline int mul()
	{
		return a*b;
	}
	inline int div()
	{
		return a / b;
	}
	inline int mod()
	{
		return a%b;
	}
};
int main()
{
	Arith a(10,4);
	cout << "Addition" << a.add() << endl;
	cout << "Subtraction" << a.sub() << endl;
	cout << "Multiplication" << a.mul() << endl;
	cout << "Division" << a.div() << endl;
	cout << "Modulus" << a.mod() << endl;
	return 0;
}