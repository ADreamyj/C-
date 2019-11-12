#include<iostream>
#include<stack>
using namespace std;


class MyQueue
{
	stack <int> s1;
	stack <int> s2;

public:

MyQueue()
{

}
void Push(int value)//插入元素
{
	s1.push(value);
}

int Pop()//删除元素
{
	if(s2.size() <= 0)
	{
		while(s1.size() > 0)
		{
			int node1 = s1.top();
			s1.pop();
			s2.push(node1);
		}
	}
	int node2 = s2.top();
	s2.pop();

	return node2;
}

int Peek()//返回首部的元素
{
	if(s2.empty())
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	return s2.top();
}
bool Empty()//判断队列是否为空
{
	return s1.empty() && s2.empty();
}
};
int main()
{
	MyQueue stackQueue;
	stackQueue.Push(1);
	stackQueue.Push(2);
	stackQueue.Push(3);
	cout << stackQueue.Pop() << endl;
	cout << stackQueue.Pop() << endl;
	stackQueue.Push(4);
	cout << stackQueue.Pop() << endl;
	cout << stackQueue.Pop() << endl;
	return 0;
}
