#include<stdio.h>
#include<string.h>
int main()
{
	char s[20];
	int i, j;
	printf("Enter the string:");
	scanf_s("%s", s);

	int l = strlen(s);
	for (i = 0; i < l; i++)
	{
		for (j = i; j < l; j++)
			printf("%c", s[j]);
		for (j = 0; j < i; j++)
			printf("%c", s[j]);
		printf("\n");
	}
	return 0;
}