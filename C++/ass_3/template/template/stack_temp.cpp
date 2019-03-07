#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
class Complex
{
	int real;
	int img;
public:
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex(int a, int b)
	{
		real = a;
		img = b;
	}
	Complex(Complex &c)
	{
		real = c.real;
		img = c.img;
	}
	Complex operator+(Complex c)
	{
		Complex temp;
		temp.real = real + c.real;
		temp.img = img + c.img;
		return temp;
	}
	Complex operator-(Complex c)
	{
		Complex temp;
		temp.real = real - c.real;
		temp.img = img - c.img;
		return temp;
	}
	Complex operator-()
	{
		real = -real;
		img = -img;
		return *this;
	}
	Complex operator++()
	{
		++real;
		++img;
		return *this;
	}
	Complex operator++(int x)
	{
		Complex temp;
		temp.real = real++;
		temp.img = img++;
		return temp;
	}
	Complex operator,(Complex c)
	{
		return c;
	}
	Complex operator=(Complex c)
	{
		real = c.real;
		img = c.img;
		return *this;
	}

	friend ostream& operator<<(ostream& cout, Complex c);
	friend istream& operator >> (istream& cin, Complex &c);

};
ostream& operator<<(ostream& cout, Complex c)
{
	cout << c.real << "+ " << c.img << "i";
	return cout;
}
istream& operator >> (istream& cin, Complex &c)
{
	cin >> c.real >> c.img;
	return cin;
}

template <class T>
class Stack
{
	T *a;
	int size1;
	int top;
public:
	Stack<T>()
	{
		top = -1;
		a = NULL;
		size1 = 0;
	}
	~Stack()
	{
		delete(a);
	}
	void setsize1(int n)
	{
		size1 = n;
		a = new T[n];
	}
	bool isEmpty()
	{
		return(top == -1);
	}
	bool isFull()
	{
		return(top == size1 - 1);
	}
	void push_complex(int real,int img)
	{
		if (!isFull())
		{
			a = new Complex[5];
			///   it is causing the previous nodes to delete CHECK
			a[++top] = Complex(real, img);
		}
		else
			throw "Stack is full";
	}
	void push_string(char* s)
	{
		if (!isFull())
		{
			a[++top] = new char[strlen(s) + 1];
			strcpy(a[top], s);
		}
		else
			throw "Stack is full";
	}
	void push(T x)
	{
		if (!isFull())
			a[++top] = x;
		else
			throw "Stack is full";
	}
	
	T pop()
	{
		if (!isEmpty())
			return a[top--];
		else
			throw "Stack is empty";
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
			cout << a[i] << " ";
	}

};
int main()
{
	Stack<int> s1;
	Stack<double> s2;
	Stack<Complex> s3;
	Stack<char*> s4;

	
	int n=0;
	int choice = 0, size1 = 0;
	double n1;

	cout << "Enter the size1 of stack:";
	cin >> size1;
	
	cout << "Enter 1 for integer stack,2 for floating numbers stack 3 for strings stack and 4 for complex number stack";
	cin >> choice;

	switch (choice)
	{
	case 1:
		s1.setsize1(size1);
		while (1)
		{
			try
			{
				cout << "Enter 1 to push 2 to pop 3 for peek 4 for display 5 to exit";
				cin >> choice;
				switch (choice)
				{
				case 1:cout << "Enter the number to push";
					cin >> n;
					s1.push(n);
					break;
				case 2:s1.pop();
					break;
				case 3:cout << "The top eleement =" << s1.peek();
					break;
				case 4:cout << "THe stack=  ";
					s1.display();
					break;
				case 5:
					exit(0);
				default:cout << "Invalid input";
				}


			}
			catch (const char*s)
			{
				cout << s;
			}
		}
		break;
	case 2:
		s2.setsize1(size1);
		while (1)
		{
			try
			{
				cout << "Enter 1 to push 2 to pop 3 for peek 4 for display 5 to exit";
				cin >> choice;
				
				switch (choice)
				{
				case 1:
					cout << "Enter the number to push";
					cin >> n1;
					s2.push(n1);
					break;
				case 2:s2.pop();
					break;
				case 3:cout << "The top eleement =" << s2.peek();
					break;
				case 4:cout << "THe stack=  ";
					s2.display();
					break;
				case 5:
					exit(0);
				default:cout << "Invalid input";
				}


			}
			catch (const char*s)
			{
				cout << s;
			}
		}
		break;
	case 3:
		s4.setsize1(size1);
		while (1)
		{
			try
			{
				cout << "Enter 1 to push 2 to pop 3 for peek 4 for display 5 to exit";
				cin >> choice;
				
				switch (choice)
				{
				case 1:char string[20];
					cout << "Enter the string to push";
					cin >> string;
					s4.push_string(string);
					break;
				case 2:s4.pop();
					break;
				case 3:cout << "The top eleement =" << s4.peek();
					break;
				case 4:cout << "THe stack=  ";
					s4.display();
					break;
				case 5:
					exit(0);
				default:cout << "Invalid input";
				}


			}
			catch (const char*s)
			{
				cout << s;
			}
		}
		break;
	case 4:
		s3.setsize1(size1);
		while (1)
		{
			try
			{
				cout << "Enter 1 to push 2 to pop 3 for peek 4 for display 5 to exit";
				cin >> choice;
				
				switch (choice)
				{
				case 1:int real, img;
					cout << "Enter the real and imaginary numbers of the complex number to push";
					cin >> real >> img;
					s3.push_complex(real, img);
					break;
				case 2:s3.pop();
					break;
				case 3:cout << "The top eleement =" << s3.peek();
					break;
				case 4:cout << "THe stack=  ";
					s3.display();
					break;
				case 5:
					exit(0);
				default:cout << "Invalid input";
				}


			}
			catch (const char*s)
			{
				cout << s;
			}
		}
		break;
	default:cout << "Invalid input";
	}
		return 0;
	
}