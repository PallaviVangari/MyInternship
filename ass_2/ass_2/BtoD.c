#include<stdio.h>
#include<math.h>
int reverse(int x)
{
	int a = 0;
	while (x != 0)
	{
		a = (a * 10) + (x % 10);
		x /= 10;
	}
	return a;
}
int binaryToDecimal(long int x)
{
	int r = 0, i = 0;
	while (x != 0)
	{
		r+= (x % 10)*pow(2, i);
		i++;
		x /= 10;
	}
	return r;
}
long int decimalToBinary(int x)
{
	long int r = 1;
	while (x != 0)
	{
		r = (r * 10) + (x % 2);
		x /= 2;
	}
	r=reverse(r);
	r = r >> 1;
	return r;

}
int main()
{
	long int b;
	printf("Enter a binary number to be converted:");
	scanf("%ld", &b);
	printf("The decimal equivalent of %ld is %d", b, binaryToDecimal(b));
	return 0;
}