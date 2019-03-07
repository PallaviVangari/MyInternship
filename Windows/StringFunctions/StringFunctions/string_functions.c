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
	str = (char*)calloc(100,sizeof(char));
	str1 = (char*)calloc(100,sizeof(char));
	
		printf("Enter the string1");
			scanf("%[^\n]s", str);
		printf("\nString 1=%s",str);
		
			printf("Enter the string2");
			scanf("%s",str1);
		printf("\nString 2=%s",str1);

	while(1)
	{
		printf("\nEnter 1 for calculating the length 2 for copying strings 3 for comparing strings 4 for concatenating strings 5 for reversing string 6 for exiting");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("The length of the string1=%d", stringLength(str));
				printf("\nThe length of the string2=%d", stringLength(str1));
			break;
		case 2 :
			stringCopy(str1, str);
			printf("\nThe string1 is copied to string2. string2 =%s", str1);
			break;
		case 3:
			printf("two Strings Comapared=%d", stringCompare(str, str1));
			break;
		case 4:

			stringConcat(str, str1);
			printf("\nThe string1 after concatenation with string2 =%s", str);
			break;
		case 5:
		
			stringReverse(str);
			printf("\nThe string1 after reversing=%s",str);
			break;
		case 6:
			exit(0);
		default:
			printf("Invalid choice");
		}

	}
	
	
	
	
	
	getchar();
	return 0;
}

