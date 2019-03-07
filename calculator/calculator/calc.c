#include<stdio.h>
#include<ctype.h>
extern int add(int, int);
extern int sub(int, int);
extern int mul(int, int);
extern int div(int, int);
static result;    
int main()
{
	char* input = NULL; 
	input = (char*)malloc(sizeof(char) * 100);
	int l = 0;
	int numbers[10];   // integer array holding the numbers in the input in same order
	for (int l = 0; l < 10; l++)  //initializing all the numbers in the array to 0
		numbers[l] = 0;
	printf( "Enter the input");
	scanf("%[^\n]s", input);
	printf("The input=%s", input);

	int i = 0,flag=0;
	int num = 0;   //each number is extracted from the input string into num variable
	int k = 0;
	int numOfOperands = 0, numOfOperators = 0;

	while (input[i] != '\0' )
	{
		if (isdigit(input[i]))   // if char is a digit
		{
			flag = 1;
			num = num * 10 +(int)(input[i]-48);   //number is calculated
			//printf("\n%d", num);
			i++;
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')   //if char is a digit
		{
			if (flag == 1)   // means the symbol was preceded by  a number
			{
				numOfOperands++;
				numOfOperators++;
				flag = 0;   
				numbers[k++] =num;
				//printf("\n%d", numbers[k - 1]);
				num = 0;
				i++;
			}
			else    // if operator is not preceded by an operand 
			{
				printf("Invalid input");
				exit(0);
			}

		}
		else         // if the input char is neither a digit nor one of the 4 operators
		{
			printf("Invalid input");
			exit(0);
		}
		
	}
	if (input[i - 1] == '+' || input[i - 1] == '-' || input[i - 1] == '*' || input[i - 1] == '/')   //if the input ends with a operator
	{
		printf("Invalid input");
		exit(0);
	}
	numbers[k] = num;   //the last number of the input is added to the array
	numOfOperands++;
/*	printf("\nThe numbers in the input in same order are:\n");
	for (l = 0; l < numOfOperands; l++)
		printf("%d ", numbers[l]);*/

	//inpt validation is done above

	i = 0;
	int sym = 0;
	while (input[i] != '\0')
	{	
		if (!isdigit(input[i]))  //on encountering an operator
		{
			
			sym++;        //the number of symbols is increased by 1

			//as * and / have equal precedence and more than that of + and - these operations are done first
			if (input[i] == '*')
			{
				
				numbers[sym - 1] = mul(numbers[sym - 1],numbers[sym]);   //the functio is performed on the numbers to the left and right of the operator 
				for (int k = sym; k < numOfOperands-1; k++)   // the array is shifted left by one place
					numbers[k] = numbers[k + 1];
				numOfOperands--;    //number of operands and operators decrease by 1
				sym--;
			}

			if (input[i] == '/')
			{
				numbers[sym - 1] = div(numbers[sym - 1],numbers[sym]);
				for (int k = sym; k < numOfOperands-1; k++)
					numbers[k] = numbers[k + 1];
				numOfOperands--;
				sym--;
			}
		}
		i++;
	}
	i = 0;
	sym = 0;
	/*printf("The numbers after mul and div:");
	for (int k = 0; k < numOfOperands; k++)
		printf(" %d ", numbers[k]);*/
	while (input[i] != '\0')
	{
		if (!isdigit(input[i]))
		{
			
			if (input[i] == '+')
			{
				sym++;
				numbers[sym - 1] = add(numbers[sym - 1],numbers[sym]);
				for (int k = sym; k < numOfOperands-1; k++)
					numbers[k] = numbers[k + 1];
				numOfOperands--;
				sym--;
			}

			if (input[i] == '-')
			{
				sym++;
				numbers[sym - 1] = sub(numbers[sym - 1],numbers[sym]);
				for (int k = sym; k < numOfOperands-1; k++)
					numbers[k] = numbers[k + 1];
				numOfOperands--;
				sym--;
			}
			
		}
		i++;
	}
	printf("The result=%d", numbers[0]);
	free(input);
	getchar();
	return 0;
}