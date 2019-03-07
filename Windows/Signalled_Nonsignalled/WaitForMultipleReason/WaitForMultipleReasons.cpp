#include<Windows.h>
#include<iostream>
using namespace std;

/*bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(4000) and thread2 Sleep(3000)
bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(2000) and thread2 Sleep(3000)
These 2 cases not done
*/
DWORD WINAPI thread_fun1(LPVOID lparam)
{
	cout << "In thread function 1\n";
	Sleep(4000);
	return 0;
}
DWORD WINAPI thread_fun2(LPVOID lparam)
{
	cout << "In thread function 2\n";
	Sleep(3000);
	return 0;
}
int main()
{
	HANDLE hThread1, hThread2;
	DWORD thId1, thId2;

	hThread1 = CreateThread(NULL, 0, thread_fun1, NULL, 0, &thId1);
	hThread2 = CreateThread(NULL, 0, thread_fun2, NULL, 0, &thId2);

	if (hThread1 == NULL)
	{
		cout << "Error in creating thread1 ";
		exit(0);
	}
	if (hThread2 == NULL)
	{
		cout << "Error in creting thraed2";
		exit(0);
	}
	HANDLE arr_handle[2] = { hThread1,hThread2 };
	//DWORD dw = WaitForMultipleObjects(2, arr_handle, TRUE, INFINITE);  //both threads get executed and both r terminated
	//DWORD dw = WaitForMultipleObjects(2, arr_handle, FALSE, INFINITE);  //one thread terminates
	//DWORD dw = WaitForMultipleObjects(2, arr_handle, FALSE, INFINITE);  
	DWORD dw = WaitForMultipleObjects(2, arr_handle, FALSE, 2000);//causes a timeout
	switch (dw)
	{
	case WAIT_OBJECT_0 + 0:
		if (WAIT_OBJECT_0 + 1)
			cout << "Threads terminated";
		else
			cout << "Thread 0 terminated";
		break;
	case WAIT_OBJECT_0 + 1:
		cout << "Thread 1 terminated";
		break;
	
	case WAIT_TIMEOUT:
		cout << "Timeout";
		break;
	case WAIT_FAILED:
		cout << "Wait failed";
		break;
	default:
		cout << "No option";
	}
	getchar();
	return 0;
}