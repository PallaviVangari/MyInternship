#include<stdio.h>
#include<string.h>
void deletes(char *s1, char *s2)
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int i, j,k,flag=0;
	for (i = l1 - 1; i >= 0; i--)
	{
		flag = 0;
		for (j = 0; j < l2; j++)
		{
			if (s2[j] == s1[i])
			{
				for (k = i; k < l1 ; k++)
				{
					s1[k] = s1[k + 1];
					flag = 1;
				}
			}
			if (flag == 1)
				break;
		}
	}
}
int main()
{
	char s1[15],s2[15];
	printf("Enter the two strings");
	scanf_s("%s", s1);
	scanf_s("%s", s2);

	deletes(s1, s2);
	printf("after deleting string=%s", s1);
	return 0;
}