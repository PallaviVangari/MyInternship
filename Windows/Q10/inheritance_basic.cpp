#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));

	HANDLE g_hEvent = CreateEvent(NULL,
		FALSE,
		FALSE,
		TEXT("named_event"));

	_SECURITY_ATTRIBUTES sa;

	//ZeroMemory(sa, sizeof(sa));
	sa.bInheritHandle=
		sa.lpSecurityDescriptor=
		sa.nLength=

	BOOL ret = CreateProcess(TEXT("C://Windows//notepad.exe"),  //name of the application
		NULL,  //NULL if no command line args r given
		NULL,   //pointer to security attribute if null its children cant inherit
		NULL,   //pointer to security attributes if null the child threads cant inherit
		TRUE,   //inheritHandle
		0,
		NULL, NULL, &si, &pi);

}