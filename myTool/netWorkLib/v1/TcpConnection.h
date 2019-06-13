/*************************************************************************
  @FileName:  TcpConnection.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 12 Jun 2019 10:59:57 PM CST
 ************************************************************************/
                                                                         
#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__
#include "Socket.h"
#include "InetAddress.h"
#include "SocketIO.h"
#include "Noncopyable.h"

#include <string>
using std::string;

namespace morey
{

class TcpConnection
: Noncopyabele
{
public:
    TcpConnection(int fd);
    ~TcpConnection();

public:
    string receive();
    void send(const string & msg);
    string toString() const;
    void shutdown();

private:
    InetAddress getLocalAddr(int fd);
    InetAddress getPeerAddr(int fd);

private:
    Socket _sock;
    SocketIO _socketIO;
    InetAddress _localAddr;
    InetAddress _peerAddr;
    bool _isShutdwonWrite;
};

}//end of namespace morey

#endif

