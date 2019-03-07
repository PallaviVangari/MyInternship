#include<windows.h>
#include<iostream>
using namespace std;

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
	printf("Handle of process =%ld\n", pi.hProcess);
	printf("Process ID of process=%ld\n", pi.dwProcessId);
	printf("Primary thread id of the process=%ld", pi.dwThreadId);
	getchar();
	return 0;
}