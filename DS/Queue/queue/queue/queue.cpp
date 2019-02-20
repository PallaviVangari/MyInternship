#include<iostream>
using namespace std;

template<class T>
class queue
{
	int front, rear;
	T *a;
	int size;
public:
	queue<T>(int s)
	{
		front = -1;
		rear = -1;
		size = s;
		a = new T[size];
	}
	bool overflow()
	{
		return(size - 1 == rear);
	}
	bool underflow()
	{
		return (front == -1 && rear==-1);
	}
	void enqueue(T x)
	{
		if (overflow())
		{
			cout << "Queue is full";
			return;
		}
		if (front == -1)
			front++;
		a[++rear] = x;
	}
	T dequeue()
	{
		if (underflow())
		{
			cout << "Queue is empty";
		}
		else
		{
			int x = a[front];
			if (front == rear)
			{
				front = -1;
				rear = -1;
			}
			else
				front++;
			return x;

		}
	}
	T getFront()
	{
		if (underflow())
			cout << "queue is empty";
		else
			return a[front];
	}
	T getRear()
	{
		if (underflow())
			cout << "queue is empty";
		else
			return a[rear];
	}
	void display()
	{
		for (int i = front; i <= rear; i++)
			cout << a[i]<<" ";
	}

};
int main()
{
	queue<int> q(5);
	int ch, n;
	while (1)
	{
		cout << "\nEnter 1 to enqueue 2 to dequeue 3 for front element  4 for display 5 to exit 6 for rear element";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter the number to be put in the queue";
			cin >> n;
			q.enqueue(n);
			break;
		case 2:cout << "The number removed =" << q.dequeue();
			break;
		case 3:
			cout << "The front element of queue=" << q.getFront();
			break;
		case 4:
			cout << "The queue is:";
			q.display();
			break;
		case 5:exit(0);
			break;
		case 6:cout << "The rear element of queue=" << q.getRear();
			break;
		default:cout << "Wrong choice";
		}
	}
	return 0;

}

