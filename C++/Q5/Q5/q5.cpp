#include<iostream>
using namespace std;

class Distance2;
class Distance1;
class Distance1
{
	int m;
	int cm;
public:
	Distance1()
	{
		m = 0;
		cm = 0;
	}
	Distance1(int a, int b)
	{
		m = a;
		cm = b;
	}
	void display()
	{
		cout << m << "metres" << cm << "cm" << endl;
	}
	friend Distance1 add(Distance1 &a, Distance2 &b);
};
class Distance2
{
	int ft;
	int in;
public:
	Distance2(int a, int b)
	{
		ft = a;
		in = b;
	}
	void display()
	{
		cout << ft << "Feet" << in << "Inches" << endl;
	}
	friend Distance1 add(Distance1 &d1, Distance2 &d2);


};
Distance1 add(Distance1 &a, Distance2 &b)
{
	Distance1 temp;
	int c = (a.m * 100) + a.cm;
	int f = b.ft *30.48;
	int i = b.in*2.54;
	int C = c + f + i;
	temp.m = C / 100;
	temp.cm = C % 100;
	return temp;
}

//Distance1 add(Distance1 &a, Distance2 &b)

int main()
{
	Distance1 d1(1, 20);
	Distance2 d2(1, 5);
	Distance1 d3 = add(d1, d2);
	cout << "D1:";
	d1.display();
	cout << "D2:";
	d2.display();
	cout << "D1+D2  ";
	d3.display();
	return 0;

}