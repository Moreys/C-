/*************************************************************************
  @FileName:  TestAcceptor.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 12 Jun 2019 11:52:37 PM CST
 ************************************************************************/
                                                                         
#include "Acceptor.h"
#include "TcpConnection.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using namespace morey;


int main()
{
    Acceptor acceptor("47.106.165.214", 8888);
    acceptor.ready();
    TcpConnection conn(acceptor.accept());
    cout << conn.toString() << "has connected!" << endl;
    conn.send("welcome to server.");
    printf(">pls client data:\n");
    cout << conn.receive() << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

