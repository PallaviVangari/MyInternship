#include<iostream>
#include <string.h>
//#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class string1
{
	char *s;
	int l;
public:
	string1()
	{
		s = NULL;
		l = 0;
	}
	string1(char *a, int d)
	{
		s = (char*)malloc(d * sizeof(char));
		strcpy(s, a);
		l = d;
	}
	string1(string1 &s1)
	{
		if (s != NULL)
			free(s);
		l = strlen(s1.s);
		s = (char *)malloc(l * sizeof(char));
		strcpy(s, s1.s);
	}
	friend	ostream& operator<<(ostream &cout, string1 &s1);
};
ostream& operator<<(ostream &cout, string1 &s1)
{
	cout << s1.s;
	cout << s1.l;
	return cout;
}
int main()
{
	string1 c1("hello", 6), c2("world", 6), c3, c4;
	c3 = c1;
	cout << c1 << c2 << c3;
}

