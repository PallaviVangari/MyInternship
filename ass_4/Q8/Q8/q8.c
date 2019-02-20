#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char **ptr;
	printf("Enter the number of words:");
	scanf("%d", &n);

	ptr = (char**)malloc(n * sizeof(char*));
	int i, l;
	char temp[100];
	printf("Enter the strings:");
	for (i = 0; i < n; i++)
	{
		scanf("%s", temp);
		l = strlen(temp);
		ptr[i] = (char*)malloc((l + 1) * sizeof(char));
		strcpy(*(ptr+i), temp);
	}
	printf("\nThe strings are:");
	for (i = 0; i < n; i++)
	{
		printf("%s", *(ptr + i));
		printf("\n");
	}
	free(ptr);
	return 0;
}