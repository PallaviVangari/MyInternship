// ReadFile.cpp : Defines the entry point for the console application.
//

//#include"stdafx.h"
#include<windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

#define BUFFSIZE 256
int main(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	TCHAR ch[12] = TEXT("Write1.txt");
	//printf("%s", argv[1]);
	hFile = CreateFile(ch, //name of file
		GENERIC_WRITE|GENERIC_READ, //access given
		0,   //share mode
		NULL, // SEcurity attribute
		OPEN_EXISTING,  //open an existing file
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		cout << "Error occured .Error code:" << GetLastError();
	else
		cout << "File opened";

	TCHAR buffer[]=TEXT("PAllaviVangari");
	DWORD dwnbr;
	
	printf("buffer=%S",buffer);
	cout << "Length of buffer" << sizeof(buffer);
	BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &dwnbr, NULL);
	if (ret == 0)
		cout << "Error occured";
	cout<<"The num of chars written="<<dwnbr;

	/*TCHAR buffer1[BUFFSIZE];
	DWORD dwnbr1;
	ZeroMemory(buffer1, BUFFSIZE);
	BOOL ret1 = ReadFile(hFile, buffer1, BUFFSIZE, &dwnbr1, NULL);
	cout << "\nNumber of chars read=" << dwnbr1;
	if (ret1 == 0)
		cout << "Error occured";
	else
		printf("Text=%s", buffer1);
*/
	CloseHandle(hFile);
	getchar();
	return 0;
}
