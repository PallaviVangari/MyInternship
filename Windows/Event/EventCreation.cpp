#include<iostream>
using namespace std;
#include<Windows.h>

int main()
{
	HANDLE g_hEvent = CreateEvent(NULL,
		FALSE,
		FALSE,
		TEXT("named_event"));

	getchar();
	return 0;
}