/*************************************************************************
  @FileName:  TestEventLoop.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 13 Jun 2019 05:55:35 PM CST
 ************************************************************************/
                                                                         
#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoop.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

void onConnection(const morey::TcpConnectionPtr & conn)
{
    cout << conn->toString() << "has connected！" << endl;
    conn->send("welcome to server.");
}

void onMessage(const morey::TcpConnectionPtr & conn)
{
    //该回调函数的执行时间不宜过长  10ms
    string msg = conn->receive();
    cout << ">> receive msg from client:" << msg << endl;
    //业务处理交给
    //decode
    //compute
    //encode
    conn->send(msg);
}

void onClose(const morey::TcpConnectionPtr & conn)
{
    cout << "onClose..." << endl;
    cout << conn->toString() << "has closed!" << endl;
}

int main()
{
    morey::Acceptor acceptor("172.17.42.252",8989);
    acceptor.ready();
    
    morey::EventLoop loop(acceptor);
    loop.setConnectionCallback(onConnection);
    loop.setMessageCallback(onMessage);
    loop.setCloseCallback(onClose);
    loop.loop();
    std::cout << "Hello world" << std::endl;
    return 0;
}

