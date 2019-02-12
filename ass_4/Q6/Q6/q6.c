#include<stdio.h>
#include<string.h>
int i, j;
void reverse(char *s)
{
	if (i < j)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
		reverse(s);
	}
		return;
}
int main()
{
	char s[50];
	printf("enter the string:");
	scanf_s("%[^\n]s", s);

	i = 0;
	j = strlen(s)-1;
	reverse(s);
	printf("the string after reversing=%s", s);
	return 0;
}