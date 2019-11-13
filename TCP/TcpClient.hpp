#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

class TcpClient
{
	private:
		int sock;
		string server_ip;
		int server_port;

	public:
		TcpClient(string _ip,int _port)
			:server_ip(_ip)
			,server_port(_port)
		{
			sock = -1;
		}
		
		void InitClient()
		{
			sock = socket(AF_INET,SOCK_STREAM,0);
			if(sock < 0)
			{
				cerr << "socket error" << endl;
				exit(2);
			}
		}

		void Run()
		{
			struct sockaddr_in server;
			server.sin_family = AF_INET;
			server.sin_addr.s_addr = inet_addr(server_ip.c_str());
			server.sin_port = htons(server_port);

			if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)//连接
			{
				cerr << "connect error" << endl;
				return ;
			}
			string message;
			char buf[1024];
			while(1)
			{
				cout << "Please Enter# ";
				cin >> message;
				write(sock, message.c_str(), message.size());
				ssize_t s = read(sock, buf, sizeof(buf) - 1);
				if(s > 0)
				{
					buf[s] = 0;
					cout << "server echo# " << buf << endl;
				}
			}
		}

		~TcpClient()
		{
			if(sock > 0)
			{
				close(sock);
			}
		}

};
