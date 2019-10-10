#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	char bar[102];
	int i = 0;
	memset(bar,0,sizeof(bar));
	const char* lable = "|/-\\";

	while(i <= 100)
	{
		printf("[%-100s][%d%%][%c]\r",bar,i,lable[i%4]);
		fflush(stdout);
		bar[i++] = '#';
		usleep(10000);
	}
	printf("\n");
}

