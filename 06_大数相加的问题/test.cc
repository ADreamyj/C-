#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s1,s2,sum;
	cin >> s1 >> s2;

	if(s1.size() < s2.size())
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}

	int len = s1.size() - s2.size();
	string s3(len,'0');//较短的字符前面补'0'，使两个字符串等长
	s2 += s3;
	
	
	int flag = 0;//表示进位
	for(int i = s1.size() - 1;i >= 0; i--)
	{
		int b = (s1[i] - '0') + (s2[i] - '0') + flag;//字符转为数字，进行相加
		if(b > 9)
		{
			sum.push_back((b - 10) + '0');//数字转化为字符，存入新字符串中。
			flag = 1;
		}
		else
		{
			sum.push_back((b + '0'));//将最后一位进位插入新字符串中
			flag = 0;
		}
	}
	if(flag > 0)	
		sum.push_back(flag + '0');
	for(auto i = sum.rbegin();i != sum.rend(); ++i)//将字符串逆序输出
	{
		cout << *i;
	}
	return 0;
}
