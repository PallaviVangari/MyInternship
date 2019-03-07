#include<windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI thread_func(LPVOID param)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "i=" << i << endl;
		Sleep(1000);//thread sleeps for 1000ms
	}
	return 0;
}
int main(int argc, CHAR* argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));

	BOOL ret = CreateProcess(TEXT("C://Windows//notepad.exe"),  //name of the application
		NULL,  //NULL if no command line args r given
		NULL,   //pointer to security attribute if null its children cant inherit
		NULL,   //pointer to security attributes if null the child threads cant inherit
		FALSE,   //inheritHandle
		0,
		NULL, NULL, &si, &pi);

	if (0 == ret)
		cout << "Process not created. ERror code=" << GetLastError();
	DWORD thID1;
	HANDLE hThread1;

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

	printf("Handle of process =%ld\n", pi.hProcess);
	printf("Process ID of process=%ld\n", pi.dwProcessId);
	printf("Primary thread id of the process=%ld", pi.dwThreadId);

	printf("\n current process id=%d", GetCurrentProcessId);
	printf("\n current thread id=%d", GetCurrentThreadId());
	printf("\n  process id=%d", GetProcessId);
	printf("\n thread id=%d", GetThreadId(hThread1));
	printf("\n process id of thread=%d\n", GetProcessIdOfThread(hThread1));

	getchar();
	return 0;
}