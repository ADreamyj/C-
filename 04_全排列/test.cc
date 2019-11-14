#include<iostream>

using namespace std;

void swap(int& a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
static int count = 0;
void perm (int list[],int begin, int end)
{

	if(begin == end)//当begin = end的时候，此时的list就是一个全排列
	{
		count++;
		for(int i = 0;i <= end;i++)
		{
			cout << list[i];
		}
		cout << endl;
	}
	else
	{
		for(int i = begin;i <= end;i++)//每个元素与第一个元素进行交换
		{
			swap(list[i],list[begin]);
			perm(list,begin + 1, end);//交换后，得到子序列，利用perm得到子序列的全排列
			swap(list[i],list[begin]);//最后，将元素交换回来，复原，交换另一个元素。
		}
	}
}
int main()
{
	int list[] = {1,2,3,4};
	perm(list,0,3);
	std::cout << count << std::endl;
	return 0;
}
