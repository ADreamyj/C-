#include <iostream>
using namespace std;

//桶排序是一种非常常见的排序，这里只写出简单的桶排序的方法
//求1 - 100之间的数的排序
int main()
{
	int v[101] = {0};//创建的数组比最大的数多1
	int n , t;
	cin >> n;//输入一个数n，表示接下来有n个数

	for(int i = 1; i <= n; i++)//循环读入n个数，并进行桶排序
	{
		//scanf("%d",&t);
		cin >> t;//把每一个数读入变量t中
		v[t]++;//进行计数
	}

	for(int i = 100; i >= 0; i--)//依次判断编号1000 - 0的桶
	{
		for(int j = 1; j <= v[i]; j++)//出现几次，打印几次
		{
			cout << i << " ";
		}
	}
	cout << endl;
	//system("pause");
	return 0;
}
//算法的时间复杂度：m + n + m + n
//O(2 * (m + n));
//O(m + n);
