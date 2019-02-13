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
	Complex(int a)
	{
		real = a;
		img = a;
	}
	Complex(int a, int b)
	{
		real = a;
		img = b;
	}
	friend Complex add(Complex &a, Complex &b);
	
	friend Complex multiply(Complex &a, Complex &b);
	
	void display()
	{
		cout << real << "+i" << img;
	}
};
Complex add(Complex &a,Complex &b)
{
	Complex temp;
	temp.real = a.real + b.real;
	temp.img = a.img + b.img;
	return temp;
}
Complex multiply(Complex &a,Complex &b)
{
	Complex temp;
	temp.real = (a.real*b.real) - (a.img*b.img);
	temp.img = (a.real*b.img) + (a.img*b.real);
	return temp;
}
int main()
{
	Complex c1;
	Complex c2(5), c3(2, 3);

	cout << "c1";
	c1.display();
	cout << endl << "c2=";
	c2.display();
	cout << endl << "c3=";
	c3.display();
	c1 = add(c2, c3);
	cout << "c2+c3=";
	c1.display();
	Complex c4 = multiply(c2, c3);
	cout << endl << "c2*c3=";
	c4.display();
	return 0;

}