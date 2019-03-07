#include<iostream>
using namespace std;

void expand(char *string1,char *string2)  //function for expanding the string s1 and writing the expanded string in s2
{
	int i = 0,k=0;  //i is used for moving tgh each char in s1
	
	while (string1[i] != '\0')  //till we reach end of string s1
	{
		if (string1[i] == '-')  //if we encounter '-'
		{
			char initialChar = string1[i - 1];  //char preceding the '-'
			char finalChar = string1[i + 1];   //char following the '-'
			char ch = (char)((int)initialChar + 1);   //the next char of initialChar
			while (ch < finalChar)    //till ch doesn't reach the finalChar
			{
				string2[k++] = ch;  //each char written to s2
				ch++;
			}
		}
		else                        //if we encounter character other than '-' 
			string2[k++] = string1[i];
		i++;
	}
	string2[k] = '\0';            //thee last char is set to NULL
	cout << "\n The output sting=" << string2;
}
int main()
{
	char *input;
	//string input;
	input = new char[100];
	char  *output;
	output = new char[100];
	cout << "Enter the input";
	cin >> input;

	int i = 0, flag = 0;
	while (input[i] != '\0')   // extracting each char of the input
	{
		flag = 0;
		if (input[i] == '-')    //o encountering '-'
		{
			char start = input[i - 1];   //char preceding the '-'
			char stop;
			if(input[i+1])    //if a char exists after the '-'
				stop = input[i + 1];    //char follwing the '-'
			else                        //if the string ends with '-' it is invalid
			{
				cout << "Invalid input";
				exit(-1);
			}
			try
			{
				if ((islower(start) && islower(stop)) && start <= stop);  //if start and stop both are lower case and start is a letter before stop

				else if ((isupper(start) && isupper(stop)) && start <= stop); //if start and stop both are upper case and start is a letter before stop

				else if ((isdigit(start) && isdigit(stop)) && start <= stop); //if start and stop both are numbers and start<=stop

				else   //if none of the above statements satisfy
					throw "'-' should be embedded between either two lower case alphabet or two upper case alphabet or two digits";
			}
			catch (const char* msg)
			{
				cout << msg;
				exit(-1);
			}
			
		}
		
		i++;
	}
	cout << "\n The input string=" << input;
	expand(input,output);
	cout << "\nThe output string=" << output;
	delete(input);
	delete(output);
	getchar();
	return 0;

}