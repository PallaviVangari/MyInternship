#include<windows.h>
#include<iostream>
using namespace std;

int main(int argc,LPTSTR argv[])
{
	HANDLE hFile;
	hFile = CreateFile(argv[1], //name of file
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
	CloseHandle(hFile);
	getchar();
	return 0;
}