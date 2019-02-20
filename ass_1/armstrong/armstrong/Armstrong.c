#include<stdio.h>
int main()
{
	int n, r, a = 0;
	printf("Enter a number:");
	scanf("%d", &n);

	int i = n;
	while (i != 0)
	{
		r = i % 10;
		a += r*r*r;
		i /= 10;
	}
	if (a == n)
		printf("Its an armstrong number");
	else
		printf("IT is not an armstrong");
	return 0;

}