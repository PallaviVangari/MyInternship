#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char s[n][25];
	printf("Enter The num of strings: ");
	scanf_s("%d", &n);

	printf("Enter the strings");
	for (i = 0; i < n; i++)
		scanf_s("%s", s[i]);

	for (i = 0; i < n - 1; i++)
	{
		if (strcmp(s[i], s[i + 1]) > 0)
		{
			char temp[] = s[i];
			s[i] = s[i + 1];
			s[i + 1] = temp;
		}
	}
}