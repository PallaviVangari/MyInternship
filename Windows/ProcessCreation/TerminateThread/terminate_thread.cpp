#include<Windows.h>
#include<iostream>
using namespace std;

HANDLE hThread1, hThread2;
DWORD WINAPI thread_fun(LPVOID param)
{

	for (int i = 0; i < 5; i++)
	{
		cout << i << " ";
		//Sleep(1000);
	}


	return 0;
}
int main()
{
	DWORD thId1, thId2;

	DWORD ch;
	hThread1 = CreateThread(NULL, 0, thread_fun, NULL, NULL, &thId1);
	if (hThread1 == NULL)
	{
		cout << "Error in creatig thread";
		return -1;
	}
	TerminateThread(hThread1, 45);  //terminates thread whose handle is passed and the error code is taken as 45
	WaitForSingleObject(hThread1, INFINITE); //the main thread waits for the child thread till it finishes its execution
	BOOL check = GetExitCodeThread(hThread1, &ch); // error code is written in ch
	if (check == 0)
		cout << "Error in get exit code";
	else
		printf("\nExit code=%ld\n", ch);

	hThread2 = CreateThread(NULL, 0, thread_fun, NULL, NULL, &thId2);
	if (hThread2 == NULL)
	{
		cout << "Error in creating thread";
		return -1;
	}

	//CloseHandle(hThread1);
	CloseHandle(hThread2);
	getchar();
	return 0;


}