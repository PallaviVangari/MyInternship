#include<stdio.h>
#include<math.h>
int main()
{
	int hex,choice,ch,com,n;
	printf("Enter a hexadecimal number");
	scanf_s("%x", &hex);

	//printf("%d", (int)(pow(2, 32) - 1));

	while (1)
	{
		choice = 0;

		printf("Enter 1 for hex eq of 1's complement\n 2 for masking\n 3 for bit shifting operation \n 4 for exit\n");
		scanf_s("%d", &choice);
		ch = 0;
		
		switch (choice)
		{
		case 1:
			com = 0;
			com = hex ^ 0xFFFFFFFF;
			printf("one's complement =%x", com);
			break;
		case 2:
			ch = 0;
			printf("Enter 1 for And 2 for or 3 for xor");
			scanf_s("%d", &ch);
			int m;
			printf("Enter a value for mask");
			scanf_s("%x", &m);
			if (ch == 1)
				printf("after bitwise and :%x", hex&m);
			else if (ch == 2)
				printf("after bitwise or :%x", hex | m);
			else if (ch == 3)
				printf("after bitwise xor:%x", hex^m);
			break;
		case 3:
			ch = 0;
			printf("enter 1 for left shift and 2 for right shift");
			scanf_s("%d", &ch);
			printf("enter the no of bits:");
			scanf_s("%d", &n);
			if (ch == 1)
				printf("After left shift: %x", hex << n);
			else if (ch == 2)
				printf("after right shift: %x", hex >> n);
			break;
		case 4:
			break;
		}
		if (choice == 4)
			break;
	}

	//getch();
	return 0;
}