#ifndef SERVER_H
#define SERVER_H

#include <thread>
using std::thread;

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "json.hh"
using json = nlohmann::json;
 

#define MAX_SIZE 8192

class Server {
private:
    int myport;
    struct sockaddr_in my_addr;

public:  
    Server();
    void handdleConnection(int sock, struct sockaddr_in* newConn);
};

Server::Server() {
    int tcp_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (tcp_socket < 0) {
        return;
    }

    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(3001);

    if (bind(tcp_socket, (struct sockaddr *) &my_addr, sizeof(my_addr)) < 0) {
        return;
    }

    if (listen(tcp_socket, 1) < 0) {
        return;
    }


    while(1) {
        struct sockaddr_in clientAddr;
        socklen_t addrLen = sizeof(clientAddr);
        int conn = accept(tcp_socket, (struct sockaddr *) &clientAddr, &addrLen);
        if (conn < 0) {
            return;
        }

        thread t1(handdleConnection, conn, clientAddr);

        t1.detach();
    }
}

void Server::handdleConnection(int sock, struct sockaddr_in* newConn) {
    char buff[MAX_SIZE];
    ssize_t r;
    while (1) {
        r = read(sock, buff, MAX_SIZE);

        if (r < 0) {
            return;
        } else if (r == 0) {
            break;
        }
    }

    json j;
    if (strcpy(j, buff) == NULL) {
        return;
    }

    
}


#endif


