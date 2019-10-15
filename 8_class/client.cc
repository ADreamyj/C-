#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd = open("fifo",O_WRONLY);
	if(fd < 0)
	{
		printf("open error\n");	
		return 1;
	}
	
	char buf[1024];
	while(1)
	{
		printf("Please enter your message: ");
		fflush(stdout);
		ssize_t s = read(0,buf,sizeof(buf) - 1);
		if(s > 0)
		{
			buf[s - 1] = 0;
			write(fd,buf,strlen(buf));
		}
		else if(s == 0)
		{
			printf("client quit\n");
			break;
		}
		else
		{
			printf("read error!\n");
			break;
		}
	}
	close(fd);
	return 0;
}
