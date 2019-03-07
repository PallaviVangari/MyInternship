#include<iostream>
using namespace std;

int *a, n;
void quick_sort(int low, int high)
{
	int i = low+1, j = high-1;
	int pivot = a[low];
	if (low < high)
	{
		
		do
		{
			while (a[i] < pivot && i<high)
			 { i++; } 
			while (a[j] > pivot)
			 { j--; } 
			if (i < j)
				swap(a[i], a[j]);
		} while (i < j);
		swap(a[low], a[j]);
		quick_sort(low, j);
		quick_sort(j+1, high);
	}
}
int main()
{
	//int *arr;
	a = new int[10];
	int n, i = 0;
	cout << "enter the numbers in the array. enter -999 when done";
	cin >> n;
	while (n != -999)
	{
		a[i++] = n;
		cin >> n;
	}
	cout << "The array before sort:";
	for (int j = 0; j < i; j++)
		cout << a[j] << " ";
	cout << endl;
	quick_sort(0,i);
	cout << "The array after sort:";
	for (int j = 0; j < i; j++)
		cout << a[j] << " ";
	cout << endl;
	return 0;

}