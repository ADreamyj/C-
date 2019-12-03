#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> v;
		v.resize(n);
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		int last = 0;
		int boollast = n - 1;
		for(int i = 0;i < n - 1;i++)//n个数排序，只需要n - 1趟
		{
			bool flag = true;
			for(int j = 0;j < boollast;j++)//如果后面的数已经排列整齐，就讲结束位置向前移动
			{
				if(v[j] > v[j + 1])
				{
					swap(v[j],v[j + 1]);
					flag = false;
					last = j;
				}
			}
			boollast = last;
			if(flag == true)//如果一趟没有发生交换，那么就跳出当前循环
				break;
		}

		for(int i = 0;i < n;i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
