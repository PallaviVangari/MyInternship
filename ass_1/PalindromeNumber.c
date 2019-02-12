#include<stdio.h>
int main()
{
  int n,sum=0,k;
  printf("Enter a number:");
  scanf("%d",&n);
  k=n;
  while(n!=0)
  {
   sum=sum*10+n%10;
   n=n/10;
  }
  if(sum==k)
  printf("\n %d is a Palindrome number",k);
  else
  printf("\n %d is not a Palindrome number",k);
  return 0;
}


