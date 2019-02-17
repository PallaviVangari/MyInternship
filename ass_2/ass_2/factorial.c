#include<stdio.h>

long int factorial(int x)
{
	int i;
	long int f = 1;
	for (i = 1; i <=x; i++)
		f *= i;
	return f;
}
int main()
{
	int a;
	printf("Enter a number");
	scanf("%d", &a);
	printf("Factorial of %d is %ld", a, factorial(a));
	return 0;
}