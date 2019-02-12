#include<stdio.h>
int main()
{
	float table[2][3] = { { 1.1,1.2,1.3 },{ 2.1,2.2,2.3 } };
	printf("%p\n", table);//base address of table
	printf("%p\n", table+1);//1st row  starting address
	printf("%p\n", *(table+1));//1st row ist element address
	printf("%p\n", (*(table + 1)+1));//1st row 1st element address
	printf("%p\n", (*(table) + 1));//address of 0th row 1st element
	printf("%f\n", *(*(table + 1) + 1));//1st row 1st element
	printf("%f\n", *(*(table)+1));//0th row 1st element
	printf("%f", *(*(table)+1)+ 1);//0th row first element +1
	getch();
	return 0;

}