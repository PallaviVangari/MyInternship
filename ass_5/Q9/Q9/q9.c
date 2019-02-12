#include<stdio.h>
#include<ctype.h>
int main()
{
	char s[100],f[10];
	printf("Enter the text");
	scanf("%[^\n]s", s);
	FILE* fp;
	printf("Enter the file name:");
	scanf("%s", f);
	fp = fopen(f, "w");

	int i = 0;
	while (s[i])
	{
		if (isupper(s[i]))
			fputc(tolower(s[i]), fp);
		else if (islower(s[i]))
			fputc(toupper(s[i]), fp);
		else
			fputc(s[i], fp);
		i++;
	}
	fclose(fp);
	return 0;
}