/**
**	Create Date: Dec. 06,2013 AT 16:59
** 	Author: slyang@aliyun.com
**	Description: main.cpp
*/

#include <iostream>

#include "socket.h"

int main(int argc, char* argv[])
{

	char recv_data_buff[1024] = {0};
	char send_data_buff[1024] = "congrate, your messge was received.\0";

	Socket serv_socket;
	serv_socket.Create();
	serv_socket.Bind();
	serv_socket.Listen();

	while(true)
	{
		int newconn = serv_socket.Accept();
		/*int size = serv_socket.Receive_Data(recv_data_buff, newconn);*/
		while(serv_socket.Receive_Data(recv_data_buff, newconn) > 0){
			std::cout << recv_data_buff << std::endl;
			serv_socket.Send_Data(send_data_buff, newconn);
		}


	}
	
	
	serv_socket.Destory();
	return 0;
}
