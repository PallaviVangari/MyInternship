#include<iostream>
#include<Windows.h>
using namespace std;
DWORD WINAPI thread_fun(LPVOID lparam)
{
	Sleep(1000);
	cout << "In the thread function";
	
	return 0;
}
int main()
{
	HANDLE hThread;
	DWORD thId;
	hThread = CreateThread(NULL, 0, thread_fun, NULL, 0, &thId);
	DWORD dw = WaitForSingleObject(hThread, INFINITE);//2nd argument is the max time span it has to wait
		switch (dw)
		{
		case WAIT_OBJECT_0:
			cout << "Thread terminated";
			break;
		case WAIT_TIMEOUT:
			cout << "Timeout";
			break;
		case WAIT_FAILED:
			cout << "Wait failed";
			break;
		}
		getchar();
		return 0;
}