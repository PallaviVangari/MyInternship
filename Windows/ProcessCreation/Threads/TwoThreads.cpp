#include<Windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI thread_func(LPVOID param)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "i=" << i<<endl;
		Sleep(1000);//thread sleeps for 1000ms
	}
	return 0;
}
int main()
{
	DWORD thID1, thID2;
	HANDLE hThread1, hThread2;

	hThread1 = CreateThread(NULL,//takes default security attribute
		0,//default for stck size
		thread_func,//callback function
		NULL,//parameter to callback function
		0,//creation flags	
		&thID1);
	if (hThread1 == NULL)
	{
		cout << "Unable to create 1st thread. Error code=" << GetLastError();
		getchar();
		return -1;
	}
	hThread2 = CreateThread(NULL,//takes default security attribute
		0,//default for stck size
		thread_func,//callback function
		NULL,//parameter to callback function
		0,//creation flags	
		&thID2);
	if (hThread2 == NULL)
	{
		cout << "Unable to create 2ndthread. Error code=" << GetLastError();
		getchar();
		return -1;
	}
	cout << "The two threads asynchronously execute the same function";
	getchar();
	return 0;
}