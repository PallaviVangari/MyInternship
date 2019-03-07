// ReadFile.cpp : Defines the entry point for the console application.
//
//#include"stdafx.h"
#include<windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

#define BUFFSIZE 100
int main(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	TCHAR ch[] = TEXT("Welcome.txt");
	//printf("%s", argv[1]);
	hFile = CreateFile(ch, //name of file
		GENERIC_READ, //access given
		0,   //share mode
		NULL, // SEcurity attribute
		OPEN_EXISTING,  //open an existing file
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		cout << "Error occured .Error code:" << GetLastError();
	else
		cout << "File opened";

	TCHAR buffer[BUFFSIZE];
	DWORD dwnbr;
	while (1)
	{
		ZeroMemory(buffer, BUFFSIZE);
		BOOL ret = ReadFile(hFile, buffer, BUFFSIZE-1, &dwnbr, NULL);
		if (ret == 0)
		{
			cout << "Error occured";
			getchar();
			return -1;
		}
		else if (ret && dwnbr == 0)
		{
			cout << "Reached EOF";
			CloseHandle(hFile);
			getchar();
			return 0;
		}
		cout << "Numof chars read=" << dwnbr<<endl;
			printf("Text=%s", buffer);
	}

	CloseHandle(hFile);
	getchar();
	return 0;
}
