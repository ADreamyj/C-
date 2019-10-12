#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
using namespace std;


//int main()
//{
//	pid_t id = fork();
//	if(id == 0)
//	{
//		//子进程
//		cout << "I am a child...." << endl;
//		
//		sleep(5);
//		//sleep(10);
//		exit(1);
//	}
//	else
//	{//父进程
//		wait(NULL);
//		cout << "I am a father ..." << endl;
//		//sleep(20);
//		//wait(NULL);
//
//		//sleep(5);
//		
//	}
//	return 0;	
//}
//
//

int main()
{
	pid_t id = fork();
	if(id == 0)
	{
		//child
		printf("child : pid : %d, ppid : %d \n",getpid(),getppid());
		sleep(5);
		exit(13);
	}
	else
	{
		//father
		printf("father : pid : %d , ppid : %d\n",getpid(),getppid());
		int status = 0;
		
		
		while(1)
		{
			int ret = waitpid(id, &status, WNOHANG);
		    
			if(ret < 0)
		    {
		    	printf("wait error , wait ret : %d\n",ret);
		    	break;
			}
		    else if(ret > 0)
		    {
		    	printf("wait success... : %d\n",ret);
		    	printf("exit status ... : %d\n",(status >> 8)&0xff);//获取子进程的退出状态
		    	printf("exit signal ... : %d\n",status & 0x7f);//信号结束的标志
		    }
			else
			{
				sleep(1);
				printf("parent wait again\n");
			}
		}
		sleep(5);
	}
	return 0;
}
