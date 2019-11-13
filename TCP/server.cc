#include "TcpServer.hpp"


// ./TcpServer IP PORT

void Usage(string proc)
{
	cout << proc << "IP PORT" << endl;
}
int main(int argc,char * argv[])
{
	if(argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
	TcpServer *t = new TcpServer(argv[1],atoi(argv[2]));
	t->InitServer();
	t->Start();
	delete t;
}

