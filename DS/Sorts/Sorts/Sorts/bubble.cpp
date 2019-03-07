#include<iostream>
using namespace std;

void bubble_sort(int *a,int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
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
		cout << arr[j]<<" ";
	cout << endl;
	bubble_sort(arr, i);
	cout << "The array after sort:";
	for (int j = 0; j < i; j++)
		cout << arr[j] << " ";
	cout << endl;
	return 0;

}