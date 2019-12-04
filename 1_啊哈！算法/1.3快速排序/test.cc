#include <iostream>
using namespace std;

//快排的时间复杂度平均是O(n * lgn)
//最坏情况下是O(n * n)
int v[1000] = {0};
int n;
void quicksort(int left, int right)
{
	if(left > right)
		return ;
	int temp = v[left];
	int i = left;
	int j = right;
	
	while(i < j)
	{
		while(i < j && v[j] >= temp )//先从右往左找
			--j;
		while(i < j && v[i] <= temp)//再从左往右找
			++i;
		if(i < j)
			swap(v[i],v[j]);
	}
	v[left] = v[j];
	v[j] = temp;

	quicksort(left,j - 1);//处理左边的数值
	quicksort(j + 1, right);//处理右边的数值
}
int main()
{
	while(cin >> n)
	{
		for(int i = 0;i < n;i++)
		{
			cin >> v[i];
		}
		quicksort(0,n - 1);//快排调用

		for(int i = 0;i < n;i++)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
