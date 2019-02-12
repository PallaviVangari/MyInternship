#include<stdio.h>
int main()
{
	char *color[6] = { "red","green", "blue", "white", "black", "yellow" };
	printf("%p\n", color);
	printf("%p\n", color + 2);
	printf("%p\n", *color);
	printf("%p\n", *(color + 2));
	printf("%p", *(color + 5));

	getch();
	return 0;
}