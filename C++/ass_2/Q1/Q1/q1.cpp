#include<iostream>
using namespace std;

class Polar
{
	int angle;
	int radius;
	
public:
	Polar()
	{
		angle = 30;
		radius = 5;
		count++;
	}
	Polar(int a, int b)
	{
		angle = a;
		radius = b;
		count++;
	}
	~Polar()
	{
		count--;
	}
	static int count;
};

int Polar::count;
int main()
{
	Polar p1;
	
	cout << "Count=" << Polar:: count;
	Polar p2(23, 8);
	cout << endl << "Count(No. of active objects):" << Polar:: count << endl;
	{
		Polar p3;
		cout << "Count=" << Polar:: count << endl;
	}
	cout << "Count" << Polar:: count;
	return 0;

}