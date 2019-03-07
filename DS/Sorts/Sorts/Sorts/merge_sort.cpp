#include<iostream>
using namespace std;

void merge(int low, int mid, int high);
int *a;
void merge_sort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}
}
void merge(int low, int mid, int high)
{
	int mid_next = mid + 1;
	int *l3, i, j, k = 0;
	l3 = new int[high - low + 1];
	i = low;
	j = mid_next;
	while (i <= mid && j <= high)
	{
		if (a[i] > a[j])
			l3[k++] = a[j++];
		else if (a[i] < a[j])
			l3[k++] = a[i++];
		else
		{
			l3[k++] = a[i++];
			l3[k++] = a[j++];
		}

	}
	while (i <= mid)
	{
		l3[k++] = a[i++];
	}
	while (j <= high)
	{
		l3[k++] = a[j++];
	}
	while (high >= low)
		a[high--] = l3[--k];
	delete(l3);

}
int main()
{
	int i=0, j,n;
	a = new int[10];
	cout << "Enter the numbers. when the insertion is finished enter -999";
	while (1)
	{
		cin >> n;
		if (n == -999)
			break;
		a[i++] = n;
	}
	cout << "The array before sorting";
	for (j = 0; j < i; j++)
		cout << a[j] << " ";
	merge_sort(0, i - 1);
	cout << "\nThe array after sorting";
	for (j = 0; j < i; j++)
		cout << a[j] << " ";
	return 0;
}