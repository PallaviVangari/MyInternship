#include<iostream>
#include"Stack.h"
using namespace std;

class PostEval
{
	Stack<char> st;
	int res;
	int len;
public:
	PostEval()
	{
		len = 0;
		res = 0;
		st.setSize(20);
	}
	int postEval(char *a)
	{
		len = strlen(a);
		int a1 = 0, b = 0;
		for (int i = 0; i < len; i++)
		{
			if (isdigit(a[i]))
				st.push(a[i]);
			else if (a[i] == '@')
				st.push(a[i]);
			else
			{
				st.pop();
				int n = 1;
				while (st.peek() != '@')
				{
					n = (n * 10) + ((int)st.pop() - 48);
				}
				a1 = reverse(n)/10;

				//cout << endl << a1;
				n = 1;
				st.pop();
				while (st.peek() != '@' && !st.isEmpty() && isdigit(st.peek()))
				{
					//cout << st.peek();
					n = (n * 10) + ((int)st.pop() - 48);
				}
				b = reverse(n)/10;
				cout << endl << b;
				//cout << st.peek();
				//int a1 = (int)st.pop() - 48;
				//cout << endl <<a1;
				//int b = (int)st.pop() - 48;
				//cout << endl<<b;
				res = eval(a[i], a1, b);
				//cout << endl << res;
				res = res * 10 + 1;
				res=reverse(res);
				while (res != 1)
				{
					int d = res % 10;
					st.push((char)(d+ 48));
					res /= 10;
				}
				st.push('@');

			}
		}
		st.pop();
		int n = 1;
		while (!st.isEmpty())
			n = (n * 10) + ((int)st.pop() - 48);
		n=reverse(n);
		return n/10;
	}
	int eval(char c, int a, int b)
	{
		switch (c)
		{
		case '+':return b + a;
		case '-':return b - a;
		case '*':return b*a;
		case '/':return b / a;
		}
	}
	int reverse(int x)
	{
		int a = 0;
		while (x != 0)
		{
			a = (a * 10) + (x % 10);
			x /= 10;
		}
		return a;
	}
};
int main()
{
	PostEval p;
	char *s;
	s = new char[10];
	cout << "Enter the postfix:";
	cin >> s;
	cout << "\nAnswer=" << p.postEval(s);
	return 0;
}