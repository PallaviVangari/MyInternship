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
		st.setSize(10);
	}
	int postEval(char *a)
	{
		len = strlen(a);
		int a1=0,b=0;
		for (int i = 0; i < len; i++)
		{
			if (isdigit(a[i]))
				st.push(a[i]);
			else
			{
				//cout << st.peek();
				int a1 = (int)st.pop()-48;
				//cout << endl <<a1;
				int b =(int) st.pop()-48;
				//cout << endl<<b;
				res=eval(a[i], a1, b);
				//cout << endl << res;
				st.push((char)(res+48));
			}
		}
		return (int)st.peek()-48;
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
};
int main()
{
	PostEval p;
	char *s;
	s = new char[10];
	cout << "Enter the postfix:";
	cin >> s;
	cout<<"\nAnswer="<<p.postEval(s);
	return 0;
}