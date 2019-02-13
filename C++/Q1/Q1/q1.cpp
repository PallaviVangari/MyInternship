#include<iostream>
using namespace std;
class Time
{
	int h;
	int m;
	int s;
public:
	Time()
	{
		h = 0;
		m = 0;
		s = 0;
	}
	Time(int a, int b, int c)
	{
		h = a;
		m = b;
		s = c;
	}
	void display()
	{
		cout << "Time:" << h << ":" << m << ":" << s;
	}
	void add(Time &t1,Time &t2)
	{
		s = t1.s + t2.s;
		if (s >= 60)
		{
			s = 0;
			m = 1;
		}
		m+= t1.m + t2.m;
		if (m >= 60)
		{
			m = 0; h = 1;
		}
		h += t1.h + t2.h;
		if (h >= 24)
			h = h-24;
	}
};
int main()
{
	Time t3;
	Time t1(1, 23, 23);
	Time t2(2, 32, 32);
	

	cout << "Time 1:";
	t1.display();
	cout << "Time 2:";
	t2.display();
	t3.add(t1, t2);
	cout << "Time 3:";
	t3.display();

	return 0;
}
