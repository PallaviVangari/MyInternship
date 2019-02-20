#include<iostream>
//#include<cytpe.h>
#include"Stack.h"
using namespace std;

class InToPost
{
	char *s;
	int len;
	Stack<char> st;
public:
	InToPost()
	{
		s = NULL;
		len = 0;
		st.setSize(10);
	}
	char* intopost(char*a)
	{
		len = strlen(a);
		s = new char[len + 1];
		int k = 0;

		for (int i = 0; i < len; i++)
		{
			if (isalpha(a[i]))
				s[k++] = a[i];
			else if (a[i] == '(')
				st.push(a[i]);
			else if (a[i] == ')')
			{
				while (st.peek() != '(')
					s[k++] = st.pop();
				st.pop();
			}
			else
			{
				if (st.isEmpty())
					st.push(a[i]);
				else
				{
					
					while ((!st.isEmpty())&&(precedence(a[i]) <= precedence(st.peek())))
						s[k++] = st.pop();
					st.push(a[i]);
				}
			}
		}
		while (!st.isEmpty())
			s[k++] = st.pop();
		return s;

	}
	int precedence(char c)
	{
		switch (c)
		{
		case '(':
			return 0;
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		}
	}
};
int main()
{
	InToPost in;
	char i[20],*p;
	cout << "enter an infix statement:";
	cin >> i;
	p = new char[strlen(i)];
	p = in.intopost(i);
	cout << "\nPostfix:" << p;
	return 0;


}