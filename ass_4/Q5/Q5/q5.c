#include<stdio.h>
#include<string.h>
int main()
{
	char s[50];
	int i;
	printf("Enter the string");
	scanf_s("%[^\n]s",s);

	int l = strlen(s);
	for (i = 0; i < l; i++)
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
		else if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
	}
	printf("The string after changing =%s", s);
	return 0;
}