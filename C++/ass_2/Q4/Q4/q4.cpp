#include<iostream>
using namespace std;
class Complex
{
	int real;
	int img;
public:
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex(int a, int b)
	{
		real = a;
		img = b;
	}
	Complex(Complex &c)
	{
		real = c.real;
		img = c.img;
	}
	Complex operator+(Complex c)
	{
		Complex temp;
		temp.real = real + c.real;
		temp.img = img + c.img;
		return temp;
	}
	Complex operator-(Complex c)
	{
		Complex temp;
		temp.real = real - c.real;
		temp.img = img - c.img;
		return temp;
	}
	Complex operator-()
	{
		real = -real;
		img = -img;
		return *this;
	}
	Complex operator++()
	{
		++real;
		++img;
		return *this;
	}
	Complex operator++(int x)
	{
		Complex temp;
		temp.real = real++;
		temp.img = img++;
		return temp;
	}
	Complex operator,(Complex c)
	{
		return c;
	}
	Complex operator=(Complex c)
	{
		real = c.real;
		img = c.img;
		return *this;
	}

	friend ostream& operator<<(ostream& cout, Complex c);
	friend istream& operator >> (istream& cin, Complex &c);

};
ostream& operator<<(ostream& cout, Complex c)
{
	cout << c.real << "+ " << c.img<<"i";
	return cout;
}
istream& operator >> (istream& cin, Complex &c)
{
	cin >> c.real >> c.img;
	return cin;
}
int main()
{
	Complex c1, c2(2, 3), c3(c2);
	cout << "C1:  " << c1 << endl << "c2  " << c2 << endl;
	cout << "C3:  " << c3 << endl;
	cout << "Enter values of c1:";
	cin >> c1;
	Complex c4 = c1 + c2;
	cout << "C1+C2  " << c4;
	c2 = -c2;
	cout << " C2=-C2=  " << c2;
	c4 = c2 - c3;
	cout << endl << " C2-C3:" << c4;
	c4 = c1++;
	cout << endl << "C4=C1++   c4=" << c4 << endl;
	cout << "C1=" << c1;
	c4 = ++c1;
	cout << endl << "C4=++C1   c4=" << c4 << endl;
	cout << "C1= " << c1;
	c1 = c2;
	cout << "C1=C2:  C1=" << c1<<endl;
	c1 = c3, c4;
	cout << "c1 = c3, c4    C1=" << c1 << endl;
	c1 = (c3, c4);
	cout << "c1 = (c3, c4)    C1=" << c1 << endl;
	return 0;

}