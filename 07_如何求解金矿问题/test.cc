#include<iostream>
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

int Getgold(int gold[], int worker[], int n, int len)
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
	cout << Getgold(gold, worker, n, len) << endl;
	return 0;
}
