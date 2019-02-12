#include<stdio.h>
int main()
{
  int n,sum=0,k;
  printf("Enter a number:");
  scanf("%d",&n);
  k=n;
  while(n!=0)
  {
   sum+=n%10;
   n=n/10;
  }
  printf("\n The sum of digits of %d is %d",k,sum);
}

