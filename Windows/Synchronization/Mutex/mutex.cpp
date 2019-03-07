#include<iostream>
#include<Windows.h>
using namespace std;

HANDLE hMutex;
DWORD WINAPI thread_fun(LPVOID lparam)
{
	static int count;
	DWORD dw;
	dw = WaitForSingleObject(hMutex, INFINITE);
	switch (dw)
	{
	case WAIT_OBJECT_0:
		cout << "Thread " << count << " Writing to the database\n";
		count++;
		Sleep(1000);
		break;
	}
	if (!ReleaseMutex(hMutex))
		cout << "Mutex not released";
	return 0;
}
int main()
{
	
	hMutex = CreateMutex(NULL,//security attribute
		FALSE,//ownership
		TEXT("MyMutex"));//name of mutex
	HANDLE hThread[8];
	DWORD thId[8];
	for (int i = 0; i < 8; i++)
	{
		hThread[i] = CreateThread(NULL, 0, thread_fun, NULL, 0, &thId[i]);
	}
	getchar();
	return 0;
}