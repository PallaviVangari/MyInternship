#include<stdio.h>
int replace(char* x)
{
	int i, count = 0;
	for (i = 0; *(x + i) != '\0'; i++)
	{
		if (*(x + i) == ' ')
		{
			*(x+i) = '-';
			count++;
		}
	}
	return count;
}
int main()
{
	char c[50];
	printf("enter a string:");
	scanf("%[^\n]s",c);
	int n = replace(c);
	printf("The pointer now is %s and n=%d", c, n);
	getch();
	return 0;
}