#include "TcpClient.hpp"

void Usage(string proc)
{
	cout << "Usage: " << proc << " Sever_ip Sever_port" << endl;
}
int main(int argc ,char* argv[])
{
	if(argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
	TcpClient *c = new TcpClient(argv[1],atoi(argv[2]));
	c->InitClient();
	c->Run();
	delete c;
	return 0;
}
