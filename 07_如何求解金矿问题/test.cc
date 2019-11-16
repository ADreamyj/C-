#include <iostream>
#include <vector>
using namespace std;

//这是一道非常地道的动态规划问题
//通过状态转移方程来求解
//
//1.问题边界：金矿数为0或者工人数为0的情况
//F(n,w) = 0 (n = 0 或者 w = 0);
//
//2.当所剩工人不够挖掘当前金矿时，只有一种最优子结构
//F(n,w) = F(n - 1, w) (n >= 1, w < p[n - 1])
//
//3.在常规情况下，只有一种最优子结构
//F(n,w) = max((F(n - 1) , w) F(n - 1), w - p[n - 1] + g(n - 1)) (n >= 1, w >= p[n - 1]);
//


//方法1：时间复杂度为O(2的n次方)
/*
int Getgold1(int gold[], int worker[], int n, int len)
{
	if(n == 0 || len == 0)
		return 0;

	if(n < worker[len - 1])
	{
		return Getgold(gold, worker, n, len - 1);
	}

	return max(Getgold(gold, worker, n, len - 1) , (Getgold(gold, worker, n - worker[len - 1], len - 1) + gold[len - 1]));
}
int main()
{
	int n = 10;
	int gold[] = {200,300,350,400,500};
	int worker[] = {3,4,3,5,5};
	int len = 5;
	cout << Getgold1(gold, worker, n, len) << endl;
	return 0;
}
*/

//方法2：二维数组
//对时间复杂度做优化O(n * w)

/*
int Getgold2(vector<int> gold, vector<int> worker, int n, int len)
{
	vector<vector<int>> vv(len + 1, vector<int> (n + 1));
	for(int i = 1;i <= len; i++)
	{
		for(int j = 1;j <= n; j++)
		{
			if(j < worker[i - 1])
				vv[i][j] = vv[i - 1][j];
			else
			{
				vv[i][j] = max(vv[i - 1][j] , vv[i - 1][j - worker[i - 1]] + gold[i - 1]);
			}
		}
	}
	return vv[len][n];
}
int main()
{
	int n = 10;
	vector<int> gold = {200,300,350,400,500};
	vector<int> worker = {3,4,3,5,5};
	int len = 5;
	cout << Getgold2(gold, worker, n, len) << endl;
	return 0;
}
*/

//方法3：一维数组
//时间复杂度为O(n)
//
//
int Getgold3(vector<int> gold, vector<int> worker, int n , int len)
{
	vector<int> v(n + 1);
	for(int i = 1;i <= len; i++)
	{
		for(int j = n; j >= 1; j--)
		{
			if(j >= worker[i - 1])
			{
				v[j] = max(v[j],v[j - worker[i - 1]] + gold[i - 1]);
			}
		}
	}
	return v[n];
}
int main()
{
	int n = 10;
	vector<int> gold = {200,300,350,400,500};
	vector<int> worker = {3,4,3,5,5};
	int len = 5;
	cout << Getgold3(gold, worker, n, len) << endl;
	return 0;
}




