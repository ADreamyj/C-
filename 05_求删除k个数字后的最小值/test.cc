#include<iostream>
using namespace std;

//这个题目看着贼经典。。。秀。。。

//用一个数组，把数组看成是一个栈，当发现某个数字比他右边的数字大，那么删除该数字
//使该数位的值减1，因为右边比它小的数顶替了它。

void RemoveDidits(string num, int k)
{
	int size = num.size();
	char stack[size];//字符数组,
	int newsize = size - k;

	//遍历所有的数字
	int top = 0;
	for(int i = 0;i < size; i++)
	{
		//当栈顶的元素大于遍历到的数字，栈顶元素出栈，新的元素入栈。
		while(top > 0 && num[i] < stack[top - 1] && k > 0)
		{
			top--;//栈顶元素出栈
			k--;
			stack[top] = num[i];//新的元素入栈
		}
		stack[top++] = num[i];//剩余元素入栈，这个是最先的一次，然后依次进行判断
	}

	//找到栈中第一个非0数字的位置，依次构建新的整数字符串
	
	int offset = 0;
	while(offset < newsize && stack[offset] == '0')
	{
		offset++;
	}

	for(int i = offset ;i < newsize; i++)
	{
		cout << stack[i];
	}
	cout << endl;

}
int main()
{
	RemoveDidits("541270936",3);
	RemoveDidits("1593212",3);
	RemoveDidits("30200",1);
	RemoveDidits("10",2);
	return 0;
}
