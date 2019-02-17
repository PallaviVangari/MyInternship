#include<stdio.h>

void prime(int a, int b)
{
	int i;
	int flag = 0;
	for (i = a + 1; i < b; i++)
	{
		flag = 0;
		for(int j=2;j<=i/2;j++)
			if (i%j == 0)
			{
				flag = 1;
				break;
			}
		if (flag == 0)
			printf("%d   ", i);
	}
}
int main()
{
	int a, b;
	printf("Enter the numbers between which u want the prime numbers to be printed:");
	scanf("%d %d", &a, &b);
	printf("The prime numbers in between are:");
	prime(a, b);
	return 0;
}