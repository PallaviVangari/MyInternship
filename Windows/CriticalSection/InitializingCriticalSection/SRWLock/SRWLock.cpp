#include<Windows.h>
#include<iostream>
using namespace std;

SRWLOCK lock;
CONDITION_VARIABLE readyToConsume, readyToProduce;
#define QSIZELIMIT 5;
int numOfThreads;
volatile BOOL isRunning = TRUE;

template<class T>
class cir_queue
{
	int front, rear;
	
	T *a;
	int size;
public:
	int numOfElements;
	cir_queue<T>(int s)
	{
		front = 0;
		numOfElements = 0;
		rear = 0;
		size = s;
		a = new T[size];
	}
	bool overflow()
	{
		return(front == (rear + 1) % size);
	}
	bool underflow()
	{
		return (front == rear);
	}
	void enqueue(T x)
	{
		if (overflow())
		{
			cout << "Queue is full";
			return;
		}
		else
		{
			rear = (rear + 1) % size;
			a[rear] = x;
			numOfElements++;
		}
	}
	T dequeue()
	{
		if (underflow())
		{
			cout << "Queue is empty";
		}
		else
		{
			int x = a[front + 1];
			front = (front + 1) % size;
			return x;
			numOfElements--;
		}
	}
	T getFront()
	{
		if (underflow())
			cout << "queue is empty";
		else
			return a[(front + 1) % size];
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
		int i;
		for (i = (front + 1) % size; i != rear; i = (i + 1) % size)
			cout << a[i] << " ";
		cout << a[i];
	}

};

cir_queue<int> SharedQ(5);
int arr[100][2];

DWORD WINAPI Writer_fun(LPVOID lparam)
{
	for (int i = 0;; i++)
	{
		int threadId= PtrToUlong(lparam);
		AcquireSRWLockExclusive(&lock);
		if (SharedQ.overflow()) 
		{
			cout << "\nWriter thread " << threadId << "Q is full cannot produce";
			SleepConditionVariableSRW(&readyToProduce, &lock, INFINITE, 0);
		}
		else
		{
			SharedQ.enqueue(i);
			cout << "\nWriter thread" << threadId<< " produced"<<i;
			ReleaseSRWLockExclusive(&lock);
			WakeAllConditionVariable(&readyToConsume);
			Sleep(1000);
		}
	}
}
DWORD WINAPI Reader_fun(LPVOID lparam)
{
	for (int i = 0;; i++)
	{
		AcquireSRWLockShared(&lock);
		if (SharedQ.underflow())
		{
			cout << "\nReader thread cant consume as the queue is empty";
			SleepConditionVariableSRW(&readyToConsume, &lock, INFINITE, 0);
		}
		else
		{
			int read_x=SharedQ.dequeue();
			cout << "\nReader thread consumed";
			ReleaseSRWLockShared(&lock);
			WakeAllConditionVariable(&readyToProduce);
			Sleep(1000);
		}
	}
}
int main()
{
	HANDLE hThreads[MAXIMUM_WAIT_OBJECTS];
	InitializeSRWLock(&lock);

	InitializeConditionVariable(&readyToConsume);
	InitializeConditionVariable(&readyToProduce);

	DWORD thId[MAXIMUM_WAIT_OBJECTS];
	for (int i = 0; i < 4; i++)
		hThreads[numOfThreads++] = CreateThread(NULL, 0, Writer_fun, (PVOID)(INT_PTR)i, 0, &thId[numOfThreads]);
	for (int i = 0; i < 2; i++)
		hThreads[numOfThreads++] = CreateThread(NULL, 0, Reader_fun, (PVOID)(INT_PTR)i, 0, &thId[numOfThreads]);
	WaitForMultipleObjects(numOfThreads, hThreads, TRUE, INFINITE);
	while (numOfThreads--)
		CloseHandle(hThreads[numOfThreads]);
	return 0;
}