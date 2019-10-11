#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

//
//int main()
//{
//	while(1)
//	{
//		printf("I am a process : pid : %d : ppid : %d\n",getpid(),getppid());
//		sleep(1);
//	}
//	return 0;
//}
//
//int main()
//{
//	printf("before\n");
//	fork();
//	printf("after\n");
//	printf("I am a process\n");
//}
//

//int main()
//{
//	pid_t id = fork();
//	if(id < 0)
//	{
//		perror("fork");
//		return 1;
//	}
//	else if(id == 0)
//	{
//		while(1)
//		{
//			printf("I am a child: pid :%d ppid : %d\n",getpid(),id);
//			sleep(1);
//		}
//	}
//	else
//	{
//		while(1)
//		{
//			printf("I am a child: pid :%d ppid : %d\n",getpid(),id);
//			sleep(2);
//		}
//	}
//	return 0;
//}


//int main(int argc,char* argv[],char * env[])
//{
//	int i = 0;
//	for(; env[i] ; ++i)
//	{
//		printf("%d : %s\n",i,env[i]);
//	}
//	return 0;
//}

//修改变量，父子进程代码共享，数据各自私有一份。

//int g_val = 100;
//
//int main()
//{
//	pid_t id = fork();
//	if(id == 0)
//	{
//		sleep(1);
//		g_val = 200;
//		printf("child: %d, %p\n",g_val,&g_val);
//	}
//	else
//	{
//		sleep(2);
//		printf("Father: %d, %p\n",g_val , &g_val);
//	}
//	return 0;
//}


int main()
{
	printf("hello world\n");
	return 0;
}


