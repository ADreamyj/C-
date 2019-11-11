#include<iostream>
using namespace std;

//求两个数的最大公因数

//方法1：碾转相除法。但是当两个整数比较大的时候，做a%b取模运算的性能会比较差
int getnum1(int a,int b)
{
	int max = a > b ? a : b;
	int min = a > b ? b : a;
	
	if(max % min == 0)
	{
		return min;
	}
	return getnum1(max % min, min);
}

//方法2：更相减损法 取出两个整数相减之后的差作为最小值，和两个整数中的较小值进行运算
int getnum2(int a,int b)
{
	if(a == b)
	{
		return a;
	}
	int max = a > b ? a : b;
	int min = a > b ? b : a;
	return getnum2(max - min ,min);
}

//方法3：对于上面两种方法的结合
int getnum3(int a,int b)
{
	if(a == b)//当a == b的时候，直接返回任何一个数
	{
		return b;
	}
	if((a&1) == 0 && (b&1) == 0)//当a和b都是偶数的时候
	{
		return getnum3(a >> 1 , b >> 1) << 1;
	}
	else if((a&1) == 0 && (b&1) != 0)//当a为偶数，b为奇数的时候
	{
		return getnum3(a >> 1, b);
	}
	else if((a&1) != 0 && (b&1) == 0)//当a为奇数，b为偶数的时候
	{
		return getnum3(a,b >> 1);
	}
	else//当a和b都为奇数的时候，可以通过更相减损法运算一次，此时a - b必为偶数，就可以用移位运算。
	{
		int max = a > b ? a : b;
		int min = a > b ? b : a;
		return getnum3(max - min,min);
	}
}
int main()
{
	//cout << getnum1(99,33) << endl;
	cout << getnum2(99,33) << endl;
	cout << getnum3(99,33) << endl;
	return 0; 	
}
