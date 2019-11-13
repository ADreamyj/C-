#pragma once

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

class TcpServer
{

	public:
		TcpServer(string _ip = "127.0.0.1",int _port = 8080)//初始化
			:ip(_ip)
			,port(_port)
		{
			listen_sock = -1;
		}
			
		void InitServer()//准备工作
		{
			listen_sock = socket(AF_INET,SOCK_STREAM,0);//(ipv4)创建套接字
			if(listen_sock < 0)
			{
				cerr << "socket error" << endl;
				exit(2);
			}
			struct sockaddr_in local;
			local.sin_family = AF_INET;//ipv4
			local.sin_addr.s_addr = inet_addr(ip.c_str());//ip
			local.sin_port = htons(port);//端口号

			if(bind(listen_sock,(struct sockaddr*)&local,sizeof(local)) < 0)//绑定
			{
				cerr << "bind error" << endl;
				exit(3);
			}

			if(listen(listen_sock,5) < 0)//监听套接字,获取新连接
			{
				cerr << "listen error" << endl;
				exit(4);
			}
		}
		void ServiceIO(int sock)//提供方法调用read
		{
			char buf[1024];
			while(1)
			{
				ssize_t s = read(sock,buf,sizeof(buf) - 1);
				if(s > 0)
				{
					buf[s] = 0;
					cout << "client# " << buf << endl;
					write(sock,buf,strlen(buf));//开始写
				}
				else if(s == 0)//s等于0代表对端连接关闭
				{
					cout << "client quit..." << endl;//客户端关闭直接退出。
					break;
				}
				else//读出错
				{
					cerr << "read error" << endl;
				}
			}
		}
		void Start()//启动
		{
			struct sockaddr_in peer;//由远端的人来连我
			while(true)
			{
				socklen_t len = sizeof(peer);
				//listen_sock只是一个获取新连接的套接字
				//sock要提供服务
				//
				int sock = accept(listen_sock,(struct sockaddr*)&peer,&len);

				if(sock < 0)
				{
					cerr << "accept error" << endl;
					continue;
				}
				cout << "get a client link..." <<endl;
				ServiceIO(sock);//通过这个函数来进行读写

				close(sock);//关闭套接字
			}
		}
		~TcpServer()//析构
		{

		}
	private:
		int listen_sock;//套接字
		string ip;//ip地址
		int port;//端口号

};
