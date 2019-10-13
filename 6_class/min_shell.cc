#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


using namespace std;
#define NUM 1024

int main()
{
    char buff[1024] = {0};
 	for(;;)
	{
		
		string tips = "[xxx@localhost YYY]# ";
		cout << tips;
		
		fgets(buff, sizeof(buff) - 1,stdin);
		buff[strlen(buff) - 1] = 0;
		
		//提取数据ls -a -l -o
		char * argv[NUM];
		argv[0] = strtok(buff," ");
		int i = 0;
		while(argv[i])
		{
			i++;
			argv[i] = strtok(NULL," ");
		}

		pid_t id = fork();
		if(id == 0)
		{
			//child
			cout << "child running ...... " << endl;
			execvp(argv[0],argv);
			exit(123);
		}
		else
		{
			int status = 0;
			waitpid(id,&status,0);
			cout << "Exit Code " << WEXITSTATUS(status) << endl;
		}
	
	}
	return 0;
}


//int main()
//{
	//execl("/usr/bin/ls", "ls", "-a", "-l", "-i", NULL);
	//execlp("ls", "ls", "-a", "-l", "-i", NULL);
	
	//char* argv[] = {"ls", "-a", "-l", "-i", NULL};
	//execv("/usr/bin/ls", argv);
	
	//execvp("ls", argv);
//	return 0;	
//}
