#include<iostream>
using namespace std;

void insertion_sort(int *a,int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] > temp)
				a[j + 1] = a[j];
			else
				break;
		}
		a[j+1] = temp;

	}
}
int main()
{
		int *arr;
		arr = new int[10];
		int n, i = 0;
		cout << "enter the numbers in the array. enter -999 when done";
		cin >> n;
		while (n != -999)
		{
			arr[i++] = n;
			cin >> n;
		}
		cout << "The array before sort:";
		for (int j = 0; j < i; j++)
			cout << arr[j] << " ";
		cout << endl;
		insertion_sort(arr, i);
		cout << "The array after sort:";
		for (int j = 0; j < i; j++)
			cout << arr[j] << " ";
		cout << endl;
		return 0;

	
}