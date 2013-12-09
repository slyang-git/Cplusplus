/**
**	Create Date: Dec. 06,2013 AT 14:55
**	Author: slyang@aliyun.com
**	Description: a socket wrapper class header file.
*/

#ifndef _SOCKET_H
#define _SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
class Socket{

	public:
	Socket();
	~Socket();
	void Create();
	void Destory();
	int  Accept();
	void Listen();
	void Bind();
	int Receive_Data(char* recv_data_buff, int& connfd);
	int Send_Data(char* send_data_buff, int& connfd);

	private:
	int m_listenfd;
	struct sockaddr_in m_serv_addr;

};


#endif // _SOCKET_H
