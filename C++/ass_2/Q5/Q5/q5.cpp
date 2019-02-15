#include<iostream>
using namespace std;

class String
{
	char* sptr;
	int len;
public:
	String()
	{
		sptr = NULL;
		len = 0;
	}
	String(char* s)
	{
		len = strlen(s);
		sptr = new char[len + 1];
		strcpy(sptr, s);
	}
	String(String &s)
	{
		len = s.len;
		sptr = new char[len + 1];
		strcpy(sptr, s.sptr);
	}
	~String()
	{
		delete[] sptr;
	}
	String operator+(String a)
	{
		String temp;
		temp.len = len + a.len;
		temp.sptr = new char[temp.len + 1];
		strcpy(temp.sptr, sptr);
		strcat(temp.sptr, a.sptr);
		return temp;
	}
	char& operator[](int n)
	{
		return sptr[n];
	}
	String operator=(String a)
	{
		if (sptr != NULL)
			delete[] sptr;
		sptr = new char[a.len + 1];
		len = a.len;
		strcpy(sptr, a.sptr);
		return *this;
	}
	friend ostream& operator<<(ostream& cout, String c);
	friend istream& operator >> (istream& cin, String &c);
};
ostream& operator<<(ostream& cout, String c)
{
	cout << c.sptr <<endl;
	return cout;
}
istream& operator >> (istream& cin, String &c)
{
	cin >> c.len >> c.sptr;
	return cin;
}
int main()
{
	String a, b("Pallavi"), c(b);
	
	//cout<<a;
	cout << "Second string" << b;
	cout << "Third string" << c;
	a = b + c;
	cout << "a=b+c   a=" << a;
	cout << "a[3]=" << a[3];
	a[3] = 'p';
	cout << "a[3]='p'  a=" << a;
	b=c = a;
	cout << "b=c=a";
	cout << "a=" << a << "   b=" << b << "   c=" << c;
	return 0;

}