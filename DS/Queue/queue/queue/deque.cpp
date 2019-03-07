#include<iostream>
using namespace std;

template<class T>
class dequeue
{
	int front, rear;
	T *a;
	int size;
public:
	dequeue<T>(int s)
	{
		front = -1;
		rear = -1;
		size = s;
		a = new T[size];
	}
	void enqueueRear(T x)
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

	T dequeueFront()
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
