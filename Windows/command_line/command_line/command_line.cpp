// command_line.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <windows.h>
#include <iostream>
using namespace std;
#include <shellapi.h>

int __cdecl main()
{
	LPWSTR *Arglist;
	int nArgs;
	int i;

	Arglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);//a pointer to the command-line string for the current process is returned by GetCommandLine
	if (NULL == Arglist)
	{
		wprintf(L"CommandLineToArgvW failed\n");
		return 0;
	}
	else
		for (i = 0; i<nArgs; i++)
			printf("%d: %S\n", i, Arglist[i]);

	// Free memory allocated for CommandLineToArgvW arguments.

	LocalFree(Arglist);

	TCHAR src[] =TEXT("%Systemroot%");
	TCHAR *des;
	des = new TCHAR[256];

	int num = ExpandEnvironmentStrings(src, des, 256);
	if (0 == num)
		cout << "Error occured in ExpandEnvironmentStrings.Error code=" << GetLastError();


	else
	{
		printf("The string is %S", des);
	}

	getchar();
	return(1);
}