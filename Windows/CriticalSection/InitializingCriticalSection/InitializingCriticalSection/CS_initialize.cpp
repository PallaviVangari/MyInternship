#include<Windows.h>
#include<iostream>
using namespace std;

CRITICAL_SECTION cs;
int sum = 0;
const int COUNT = 1000;

DWORD WINAPI thread_fun1(LPVOID param)
{
	EnterCriticalSection(&cs);
	sum = 0;
	for (int i = 0; i < 5; i++)
		sum += i;
	cout << "\nSum of first 5 natural numbers in thread1=" << sum;
	LeaveCriticalSection(&cs);
	return sum;
}
DWORD WINAPI thread_fun2(LPVOID param)
{
	EnterCriticalSection(&cs);
	sum = 0;    //shared resource
	for (int i = 0; i < 10; i++)
		sum += i;
	cout << "\nSum of first 10 natural numbers in thread2=" << sum;
	LeaveCriticalSection(&cs);
	return sum;
}

int main()
{
	InitializeCriticalSectionAndSpinCount(&cs,100);  //CS initialized can also use InitializeCS function

	DWORD thId1, thId2;
	HANDLE hThread1, hThread2;

	hThread1 = CreateThread(NULL, 0, thread_fun1, NULL, 0, &thId1); // craeting 1st thread
	hThread2 = CreateThread(NULL, 0, thread_fun2, NULL, 0, &thId2);  //creating second thread

	if (hThread1 == NULL)
	{
		cout << "Error in creating 1st thread.Error code=" << GetLastError();
		exit(-1);
	}
	if (hThread2 == NULL)
	{
		cout << "Error in creating 2nd thread.Error code=" << GetLastError();
		exit(-1);
	}

	HANDLE arr[2] = { hThread1,hThread2 };  //array of thread handlers 
	WaitForMultipleObjects(2, arr, FALSE, INFINITE); //the main thread waits for the two threads to finish before it exits
	DeleteCriticalSection(&cs);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	getchar();
	return 0;

}