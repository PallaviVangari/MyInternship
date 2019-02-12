#include<stdio.h>
void subArray(int *a,int n,int l)
{
	int i, j, sum = 0;
	//printf("%d", l);
	for (i = 0; i < l; i++)
	{
	    sum = a[i];
		for (j = i + 1; j < l; j++)
		{
			if (sum > n)
				break;
			if (sum == n)
				break;
			sum += a[j];
		}
		if (sum == n)
			break;
	}
	if (sum == n)
		printf(" The subarray from %d to %d adds upto sum", i, j-1);
	else
		printf("Sub array not found");
}
int main()
{
	int a[10], n, i = 0,s,count=0;
	printf("Enter the sum needed:");
	scanf_s("%d", &s);
	printf("Enter the numbers in the array.Enter -1 when u rdone");
	scanf_s("%d", &n);
	while (n != -1)
	{
		count++;
		a[i++] = n;
		scanf_s("%d", &n);
	}
	subArray(a,s,count);
	getch();
	return 0;
}