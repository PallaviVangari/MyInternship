

#include<Windows.h>
#include<iostream>
using namespace std;

long long int global_var;
DWORD WINAPI thread_func1(LPVOID param)
{
	//global_var++;
	InterlockedExchangeAdd64(&global_var, 1);
	cout << "Value of global variable= "<<global_var<< " in thread1\n";
	return 0;
}
DWORD WINAPI thread_func2(LPVOID param)
{
	//global_var++;
	InterlockedExchangeAdd64(&global_var, 1);
	cout << "Value of global variable= " << global_var << " in thread2\n";
	return 0;
}
int main()
{
	DWORD thID1, thID2;
	HANDLE hThread1, hThread2;
	HANDLE arr_hand[2];

	while (1)
	{
		global_var = 0;
		hThread1 = CreateThread(NULL,//takes default security attribute
			0,//default for stck size
			thread_func1,//callback function
			NULL,//parameter to callback function
			0,//creation flags	
			&thID1);
		if (hThread1 == NULL)
		{
			cout << "Unable to create 1st thread. Error code=" << GetLastError();
			getchar();
			return -1;
		}
		hThread2 = CreateThread(NULL,//takes default security attribute
			0,//default for stck size
			thread_func2,//callback function
			NULL,//parameter to callback function
			0,//creation flags	
			&thID2);
		if (hThread2 == NULL)
		{
			cout << "Unable to create 2ndthread. Error code=" << GetLastError();
			getchar();
			return -1;
		}
		arr_hand[0] = hThread1;
		arr_hand[1] = hThread2;
		WaitForMultipleObjects(2,arr_hand,TRUE, INFINITE);
		if (global_var == 1)
		{
			cout << "\nsynchronization problem";
			break;
		}
	}

	getchar();
	return 0;
}