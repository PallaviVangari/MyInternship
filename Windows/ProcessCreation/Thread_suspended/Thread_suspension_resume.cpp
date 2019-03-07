#include<iostream>
using namespace std;
#include<Windows.h>

DWORD WINAPI thread_fun(LPVOID param)
{
	for (int i = 0; i < 100; i++)
		cout << i<<" ";
	return 0;
}
int main()
{
	HANDLE hThread;
	DWORD thId,resume_ret;
	hThread = CreateThread(NULL, 0, thread_fun, NULL, CREATE_SUSPENDED, &thId);

	if (NULL == hThread)
	{
		printf( "Error in thread creation.Error code=%d",GetLastError());
		return -1;
	}
	Sleep(5000);
	resume_ret = ResumeThread(hThread);
	if (0 == resume_ret)
	{
		printf("Error in resuming thread.Error code=%d", GetLastError());
		return -1;
	}
	printf("Thread resumed normally");
	CloseHandle(hThread);
	getchar();
	return 0;
}