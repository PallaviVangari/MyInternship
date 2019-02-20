#include<stdio.h>

void negTostart(int *a,int l)
{
	int i = 0,j=l-1;
	do
	{
		while (a[i] < 0)
			i++;
		while (a[j] > 0)
			j--;
		if (i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	} while (i < j);
}
int main()
{
	int arr[10],i=0,n;
	printf("Enter the array. enter -999 to stop insertion");
	scanf("%d", &n);
	while (n!=-999)
	{
		arr[i++] = n;
		scanf("%d", &n);
	}
	negTostart(arr,i);
	printf("The array after shifting:");
	for (int j = 0; j < i; j++)
		printf("%d ", arr[j]);
	return 0;
}