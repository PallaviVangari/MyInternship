#include<iostream>
using namespace std;
template <class T>
class Stack
{
	T *a;
	int size;
	int top;
public:
	Stack<T>()
	{
		top = -1;
		a = NULL;
		size = 0;
	}
	~Stack()
	{
		delete(a);
	}
	void setSize(int n)
	{
		size = n;
		a = new T[n];
	}
	bool isEmpty()
	{
		return(top == -1);
	}
	bool isFull()
	{
		return(top == size - 1);
	}
	void push(T x)
	{
		if (!isFull())
			a[++top] = x;
		else
			cout << "Stack is full";
	}
	T pop()
	{
		if (!isEmpty())
			return a[top--];
		else
			cout << "Stack is empty";
	}
	T peek()
	{
		if (!isEmpty())
			return a[top];
		else
			cout << "Stack is empty";
	}
	void display()
	{
		for (int i = 0; i <= top; i++)
			cout << a[i] << "  ";
	}

};

class Balance
{
	Stack<char> st;
	int flag;
public:
	Balance(int n)
	{
		flag = 0;
		st.setSize(n);
	}
	void balance(char *s)
	{
		int l = strlen(s);

		for (int i = 0; i < l; i++)
		{
			char c = s[i];
			switch (c)
			{
				case '(':
				case '[':
				case '{':st.push(c);
					//st.display();
					break;
				case ')':
				case ']':
				case '}':
					if (!st.isEmpty())
					{
						if ((c == ')' && st.peek() == '(') || (c == ']' && st.peek() == '[') || (c == '}' && st.peek() == '{'))
						{
							st.pop(); //st.display();
						}
					}
					else
					{
						flag = 1;
						break;
					}
					break;
			}
			if (flag == 1)
				break;
		}
		if (flag==1 || !st.isEmpty())
			cout << "String not balanced";
		else
			cout << "String balanced";

	}
};
int main()
{
	Balance b(20);
	char *p;
	p = new char[20];
	cout << "Enter the string";
	cin >> p;
	//const char *s = "(s*h+{ha}-)";
	b.balance(p);
	return 0;
}

