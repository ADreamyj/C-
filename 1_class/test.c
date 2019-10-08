#include<stdio.h>
int MYSum()
{


   int i = 1;
   int sum = 0;
   for(;i <= 10 ;i++)
   {
      sum += i;
   }
   return sum; 
}
int main()
{
   int sum = MYSum();
   printf("sum = %d\n",sum);
   return 0;
}
