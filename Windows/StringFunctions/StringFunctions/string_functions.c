#include<stdio.h>

int stringLength(char *string)
{
	int count = 0;
	while (*string != '\0')
	{
		count++;
		string++;
	}
	return count;
}
void stringCopy(char *string1, char*string2)
{
	while ((*string1 = *string2) != '\0')
	{
		string1++;
		string2++;
	}
}
void stringConcat(char *string1, char *string2)
{
	while (*string1 != '\0')
		string1++;
	while ((*string1++ = *string2++) != '\0');

}
int stringCompare(char *string1, char *string2)
{
	while (*string1 == *string2)
	{
		if (*string1 == '\0')
			return 0;
		string1++;
		string2++;
	}
	if ((*string1 - *string2) > 0)
		return 1;
	else
		return -1;
}
void stringReverse(char *string)
{
	
	char *p1, *p2;
	for (p1 = string, p2 = string + stringLength(string) - 1; p1 < p2; p1++, p2--)
	{
		
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}
int main()
{
	char *str, *str1;
	int choice = 0;

	
	str = (char*)malloc(100*sizeof(char));
	str1 = (char*)malloc(100*sizeof(char));	   

	while(1)
	{
		printf("\nEnter 1 for calculating the length 2 for copying strings 3 for comparing strings 4 for concatinating strings 5 for reversing strig 6 for exiting");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the string");
			scanf("%s",str);
			printf("The length of the string=%d", stringLength(str));
			break;
		case 2 :

			printf("Enter the string to be copied");
			scanf("%s", str);
			stringCopy(str1, str);
			printf("The string copied =%s", str1);
			break;
		case 3:
			printf("Enter 2 strings to be compared");
			scanf("%s", str);
			scanf("%s",str1);
			printf("StringComapred=%d", stringCompare(str, str1));
			break;
		case 4:
			printf("Enter 2 strings to be concatenated");
			scanf("%s", str);
			scanf("%s",str1);
			stringConcat(str, str1);
			printf("The string after concatenation=%s", str);
			break;
		case 5:
			printf("Enter the string to be reversed");
			scanf("%s",str);
			stringReverse(str);
			printf("The string after reversing=%s",str);
			break;
		case 6:
			exit(0);
		default:
			printf("Invalid choice");
		}

	}
	
	
	
	
	free(str);
	free(str1);	
	return 0;
}

