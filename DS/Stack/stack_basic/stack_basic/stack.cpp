#include<iostream>
using namespace std;

struct stack
{
	int top;
	int *a;
	int size;
};

class Stack
{
	struct stack s;
public:
	Stack()
	{
		s.top = -1;
		s.a = NULL;
		s.size = 0;
	}
	~Stack()
	{
		delete(s.a);
	}
	void setSize(int n)
	{
		s.size = n;
		s.a = new int[n];
	}
	bool isEmpty()
	{
		return(s.top == -1);
	}
	bool isFull()
	{
		return(s.top == s.size - 1);
	}
	void push(int x)
	{
		if (!isFull())
			s.a[++s.top] = x;
		else
			cout << "Stack is full";
	}
	int pop()
	{
		if (!isEmpty())
			return s.a[s.top--];
		else
			cout << "Stack is empty";
	}
	int peek()
	{
		if (!isEmpty())
			return s.a[s.top];
		else
			cout << "Stack is empty";
	}
	void display()
	{
		for (int i = 0; i <= s.top; i++)
			cout << s.a[i] << "  ";
	}

};
int main()
{
	Stack st;
	int ch,size,n;
	cout << "Enter the size of stack";
	cin >> size;
	st.setSize(size);
	
	while (1)
	{
		cout << "\nEnter 1 to push 2 to pop 3 to peek 4 for display 5 to exit";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter the number to be pushed";
			cin >> n;
			st.push(n);
			break;
		case 2:cout << "The number poped =" << st.pop();
			break;
		case 3:
			cout << "The top element of stack=" << st.peek();
			break;
		case 4:
			cout << "The stack is:";
			st.display();
			break;
		case 5:exit(0);
			break;
		default:cout << "Wrong choice";
		}
	}
	return 0;

}