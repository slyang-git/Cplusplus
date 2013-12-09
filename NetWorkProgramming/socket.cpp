/**
**	Create Date: Dec. 06,2013 AT 15:45
**	Author: slyang@aliyun.com
**	Description: a socket wrapper class implementation file.
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

#include "socket.h"
/*Constructor*/
Socket::Socket()
{
	m_listenfd = 0;
	memset(&m_serv_addr, '0', sizeof(m_serv_addr));
}
/*Destructor*/
Socket::~Socket()
{
	
}

void Socket::Create()
{
	m_listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_listenfd < 0){
		std::cout << "ERROR Occured when creating cocket" << std::endl;
		exit(1);
	}
	m_serv_addr.sin_family = AF_INET;
	m_serv_addr.sin_addr.s_addr = INADDR_ANY;
	m_serv_addr.sin_port = htons(8888);
}

void Socket::Bind()
{
	int recd = bind(m_listenfd, (struct sockaddr *)&m_serv_addr, sizeof(m_serv_addr));
	if (recd < 0)
	{
		std::cout << "ERROR Occured when binding socket" << std::endl;
		exit(1);
	}

}

void Socket::Listen()
{
	listen(m_listenfd, 5);
}

void Socket::Destory()
{
	close(m_listenfd);
}

int Socket::Receive_Data(char* recv_data_buff, int& connfd)
{
	int data_size = read(connfd, recv_data_buff,1024);
	return data_size;
}

int Socket::Send_Data(char* send_data_buff, int& connfd)
{
	int data_size = write(connfd, send_data_buff,1024);
	return data_size;
}

int Socket::Accept()
{
	int new_connfd = accept(m_listenfd, NULL, NULL);
	if (new_connfd < 0)
	{
		std::cout << "ERROR Occured when accept" << std::endl;
		exit(1);
	}
	return new_connfd;
}
