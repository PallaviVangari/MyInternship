#include<stdio.h>

short int rotate_right(short int n, short int b)
{
	for (int i = 0; i < b; i++)
	{
		int x = n & 0b0001;
		n = n >> 1;
		if (x == 1)
			n = n | 0b10000000;

	}
	return n;
}
int main()
{
	short int n, a, b;
	printf("Enter n and b:");
	scanf("%hi %hi", &n, &b);
	a = rotate_right(n, b);
	printf("Value after rotating:%hi",a);
	return 0;
}