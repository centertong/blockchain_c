#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>

class Server {
private:
    int myport;
    struct sockaddr_in my_addr;

public:  
    Server();
};

Server::Server() {
    int tcp_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    
}

#endif