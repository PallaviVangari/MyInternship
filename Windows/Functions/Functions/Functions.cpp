// Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include<iostream>
using namespace std;

int main()
{
	char c = 'A';
	CHAR ch = 'A';

	wchar_t w = L'B';
	WCHAR wh = L'B';

	printf("characters= %c %c and wide characters= %c %c\n", c, ch, w, wh);

	CHAR ansi[] = "PAllavi";
	WCHAR wc[] = L"PALLAVIV";

	BOOL n,m;
	n = IsTextUnicode(ansi, strlen(ansi), NULL);  // ansi is the char array, size of the array, 3rd argument specifies the test to be 
	                                               //performed if it is NULL all tests r to be done
		
	if (0 == n)
		printf("%s is not unicode", ansi);
	else
		printf("%s is unicode", ansi);

	m = IsTextUnicode(wc, wcslen(wc), NULL);
	if(0==m)
		printf("\n%S is not unicode",wc);
	else
		printf("\n%S is unicode",wc);

	int num = MultiByteToWideChar(CP_UTF8, 0, ansi, -1, NULL, 0);//1st arg: UTf-8 2nd arg: it has to be 0 when UTF-8 is taken 3rd arg: string to convert 
																//4th arg:-1 if the NULL char also has to be processed if 0 is given it fails
																//5th arg:the pointer to the string where the result has to be stored 
																//6th arg: the size of the result array if it is 0 the number of chars of the array converted is passed by the function. 
	if (0 == num)
		printf("Error occured. Error code=%d", GetLastError());
	else
	{
		WCHAR *wch = new WCHAR[num];
		int check = MultiByteToWideChar(CP_UTF8, 0, ansi, -1, wch, num);
		if (0 == check)
			cout << "ERROr occured. Error code:" << GetLastError();
		else
			printf("The wide char array=%S", wch);
		/*if (IsTextUnicode(wch, wcslen(wch), NULL))
			printf("\n%S is unicode", wch);
		else
			printf("\n%S is not unicode", wch);*/
	}
	int num1 = WideCharToMultiByte(CP_UTF8, 0, wc, -1, NULL, 0,NULL,NULL);
	if(0==num1)
		printf("Error occured. Error code=%d", GetLastError());
	else
	{
		CHAR *ch = new CHAR[num1];
		int check = WideCharToMultiByte(CP_UTF8, 0, wc, -1, ch, num1,NULL,NULL);
		if (0 == check)
			cout << "ERROr occured. Error code:" << GetLastError();
		else
			printf("The char array=%s", ch);
	}
	

	//TCHAR  a[] = TEXT("U+00A3");

	TCHAR  a[] = TEXT("U+0026");

	printf("The tchar character=%S", a);


	getchar();
    return 0;
}

