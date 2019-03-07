#include<iostream>
using namespace std;

void selection_sort(int *a,int n)
{
	int min;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		if (min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
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
	selection_sort(arr, i);
	cout << "The array after sort:";
	for (int j = 0; j < i; j++)
		cout << arr[j] << " ";
	cout << endl;
	return 0;

}