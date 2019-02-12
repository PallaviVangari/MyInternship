#include<stdio.h>
#include<string.h>
void delete(char *s, char c)
{
	int l = strlen(s);
	int i,j;
	for(i=l-1;i>=0;i--)
		if (s[i] == c)
		{
			for (j = i; j < l; j++)
				s[j] = s[j + 1];
		}
}
int main()
{
	char s[50];
	char c;
	printf("Enter the character to be deleted:");
	scanf_s("%c", &c);
	printf("Enter the string ");
	scanf_s("%s", s);
	delete(s, c);
	printf("The string after deletion=%s", s);
	return 0;
}