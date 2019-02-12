#include<stdio.h>
#include<string.h>
int main()
{
  int letter=0,digit=0,space=0,tab=0;
  char text[1000];
  printf("Enter the text:");
  gets(text);
  for(int i=0;i<strlen(text);i++)
  {
      if(text[i]>=65 && text[i]<=90 || text[i]>=97 && text[i]<=122)
        letter++;
      else if(text[i]==32)
        space++;
      else if(text[i]==9)
        tab++;
      else if(text[i]>=48 && text[i]<=57)
        digit++;

    }
printf("No of Letters=%d\n",letter);
printf("No of spaces=%d\n",space);
printf("No of Tabs=%d\n",tab);
printf("No of Digits=%d\n",digit);
  return 0;
}
