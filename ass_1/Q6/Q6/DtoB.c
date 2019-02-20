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
int decimalToBinary(int x)
{
	int r = 1;
	while (x != 0)
	{
		r = (r * 10) + (x % 2);
		x /= 2;
	}
	
	r = reverse(r);
	r = r /10;
	printf("r=%d", r);
	return r;

}
int main()
{
	int n;
	printf("Enter a decimal number between 0 & 32 both exclusive");
	scanf("%d", &n);

	int a = decimalToBinary(n);
	//a =| 0b100000;
	printf("The binary equivalent=%d", a);
	return 0;

}