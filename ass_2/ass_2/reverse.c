#include<stdio.h>

int reverse(int x)
{
	int a=0;
	while (x != 0)
	{
		a = (a * 10) + (x % 10);
		x /= 10;
	}
	return a;
}
int main()
{
	int a;
	printf("enter the number to be reversed:");
	scanf("%d", &a);
	printf("The number after reversing =%d", reverse(a));
	return 0;
}