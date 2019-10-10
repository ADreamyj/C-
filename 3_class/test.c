#include<stdio.h>

//#define MAX 1234
//
//int main()
//{
//#ifdef MAX
//	printf("I have MAX\n");
//#else
//	printf("I have no MAX\n");
//#endif
//
//	//printf("hello:%d\n",MAX);
//	//printf("hello:%d\n",MAX);
//	//printf("hello:%d\n",MAX);
//	
//	printf("hello:%d\n",MAX);
//	return 0;
//}
//
int Mysum()
{
	int sum = 0;
	int i = 0;
	for(;i <= 100;++i)
	{
		sum += i;
	}
	return sum;
}

int main()
{
	int sum = Mysum();
	printf("sum = %d\n",sum);
	return 0;
}
