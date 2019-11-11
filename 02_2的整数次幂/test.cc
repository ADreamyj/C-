#include<iostream>
using namespace std;

bool getnum1(int num)
{
	int temp = 1;
	while(num >= temp)
	{
		if(num == temp)
		{
			cout << "这个数是2的倍数" <<endl;
			return true;
		}
		temp = temp << 1;
	}
	cout << "这个数不是2的倍数" << endl;
	return false;
}

bool getnum2(int num)
{
	return (num & (num - 1)) == 0;
}
int main()
{
	int num = 64;
	getnum1(num);
	cout << getnum2(num) << endl;
	return 0;
}
