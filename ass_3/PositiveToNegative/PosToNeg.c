#include<stdio.h>
int main()
{
	int a[10];
	int n, i = 0, count = 0,j,k;
	printf("Enter the numbers. Enter -1 when u r done");
	scanf_s("%d", &n);
	while (n != -1)
	{
		a[i++] = n;
		count++;
		scanf_s("%d", &n);
	}
	j = count - 1;
	for (k = 0; k < count; k++)
		printf("%d", a[k]);
	while (i < j)
	{
		while (a[i] < 0)
			i++;
		while (a[j] > 0)
			j--;
		if (i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = a[i];
		}
	}
	printf("\nTHe Array after swapping:");
	for (i = 0; i < count; i++)
		printf("%d", a[i]);
	
	getch();
	return 0;
}