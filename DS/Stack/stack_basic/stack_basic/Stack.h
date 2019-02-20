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
