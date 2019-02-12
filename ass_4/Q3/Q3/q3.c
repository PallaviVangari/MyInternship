#include<stdio.h>
int main()
{
	char * s[] = { "we will teach you how to ", "Move a mountain", "Level a building", "Erase the past", "Make a million " };	int count = 0, i,j;	int r = sizeof(s) / sizeof(char *);	printf("%d", r);	for (i = 0; i < r; i++)	{		for (j = 0; *(*(s + i) + j) != '\0'; j++)			if (*(*(s + i) + j) == 'e')				count++;	}	printf("Num of e's =%d", count);	getch();	return 0;
}