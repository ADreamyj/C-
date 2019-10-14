#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	//数组只能被整体初始化，不能被整体赋值。
	int fd[2] = {0};
	
	pipe(fd);
	
	pid_t id = fork();
	if(id == 0)
	{
		//child;w
		close(fd[0]);
		
		char message[] = "hello ....pipe ....";
		while(1)
		{
			write(fd[1], message, strlen(message));
			sleep(1);
		}
		exit(0);
	}
	else
	{
		//father;r
		close(fd[1]);

		char buf[1024];
		while(1)
		{
			ssize_t s = read(fd[0], buf, sizeof(buf) - 1);
		

			if(s > 0)
			{
				buf[s] = 0;
				printf("I am father, got child message %s\n",buf);
			}
			else if(s == 0)
			{
				printf("read file end\n");
				break;
			}
			else
			{
				printf("read error\n");
				break;
			}
		}
		waitpid(id ,NULL, 0);
	}
	return 0;
}
