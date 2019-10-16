#include<iostream>
#include<unistd.h>
#include<signal.h>
#include<cstdio>
#include<signal.h>
#include<stdlib.h>


int flag = 0;

void handler(int signo)
{
	flag = 1;
	printf("get a signal : %d, change flag : %d\n", signo, flag);
}
int main()
{
	signal(2, handler);

	while(!flag);
	
	printf("quit\n");
	return 0;	
}
//void handler(int signo)
//{
//	printf("sig is : %d\n", signo);	
//}
//int main()
//{
//	signal(2,handler);//对2号信号进行handler方法操作
//	sigset_t set, oset;//定义信号集对象
//	sigemptyset(&set);//清空初始化信号集对象
//	sigaddset(&set,2);//将2号信号添加到信号集中
//
//	sigprocmask(SIG_BLOCK,&set,&oset);//设置阻塞信号集，阻塞2号信号
//
//	int flag = 0;
//	sigset_t pi;
//	while(1)
//	{
//		sigpending(&pi);//读取当前进程的未决信号集
//		int i = 1;
//		for(;i <= 31; i++)
//		{
//			if(sigismember(&pi, i))//判断信号集中是否包含2号信号
//			{
//				printf("1 ");
//			}
//			else
//			{
//				printf("0");	
//			}
//		}
//		printf("\n");
//		sleep(1);
//		flag++;
//		
//		if(flag > 10)
//		{
//			sigprocmask(SIG_SETMASK, &oset, NULL);//取消二号信号集，二号信号应答
//		}
//	}
//	return 0;	
//}





//int count = 0;
//
//void handler(int sig)
//{
//	printf("count is : %d\n", count);	
//	exit(1);
//}
//int main()
//{
//	signal(14,handler);
//	alarm(1);
//	while(1)
//	{
//		count++;	
//	}
//	return 0;
//}

//int main()
//{
//	int count = 0;
//	alarm(1);
//	while(1)
//	{
//		printf("data is:%d\n", count++);
//	}
//}
//int main()
//{
//	sleep(3);
//	//raise(9);
//
//	abort();
//	while(1);
//	return 0;
//}

//void handler(int signo)
//{
//	printf("get a sig: %d\n", signo);	
//}
//
//int main()
//{
//	signal(SIGINT, handler);
//	while(1)
//	{
//		printf("I am running .....\n");
//		sleep(1);
//	}
//}
