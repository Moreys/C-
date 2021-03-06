/*************************************************************************
  @FileName:  Acceptor.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 12 Jun 2019 10:39:55 PM CST
 ************************************************************************/

#include "Acceptor.h"


namespace morey
{

Acceptor::Acceptor(unsigned short port)
: _addr(port)
, _listensock()
{}

Acceptor::Acceptor(const string & ip, unsigned short port)
: _addr(ip, port)
, _listensock()
{}

void Acceptor::ready()
{
    setReuseAddr(true);
    setReusePort(true);
    bind();
    listen();
}


void Acceptor::setReuseAddr(bool on)
{
    int one = on;
    if(setsockopt(_listensock.fd(),
                  SOL_SOCKET,
                  SO_REUSEADDR,
                  &one,
                  sizeof(one)) < 0)
    {
        perror("setsockopt");
    }

}

void Acceptor::setReusePort(bool on)
{
    int one = on;
    if(setsockopt(_listensock.fd(),
                  SOL_SOCKET,
                  SO_REUSEADDR,
                  &one,
                  sizeof(one)) < 0)
    {
        perror("setsockopt");
    }
}

void Acceptor::bind()
{
    int ret = ::bind(_listensock.fd(), 
                    (struct sockaddr *)_addr.getInetAddressPtr(),
                    sizeof(struct sockaddr));
    if(-1 == ret)
    {
        perror("bind");
    }
}

void Acceptor::listen()
{
    int ret = ::listen(_listensock.fd(), 10);
    if(-1 == ret)
    {
        perror("listen");
    }
}

int Acceptor::accept()
{
    int peerfd = ::accept(_listensock.fd(), NULL, NULL);
    if(-1 == peerfd)
    {
        perror("listen");
    }
    return peerfd;
}

}//end of namespace morey


