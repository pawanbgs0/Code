// server.cpp

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main() 
{
    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("socket");
        return 1;
    }

    // bind the socket to a port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
    {
        perror("bind");
        return 1;
    }

    // listen for connections
    listen(sockfd, 5);

    // accept connections
    while (true) 
    {
        struct sockaddr_in client_addr;
        socklen_t client_addrlen = sizeof(client_addr);
        int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addrlen);
        if (clientfd < 0) 
        {
            perror("accept");
            return 1;
        }

        // get the current time
        time_t now = time(NULL);

        // send the current time to the client
        struct tm *tm = localtime(&now);
        char buf[64];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm);
        send(clientfd, buf, strlen(buf), 0);

        // close the client socket
        close(clientfd);
    }

    return 0;
}

// client.cpp

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main() 
{
    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("socket");
        return 1;
    }

    // connect to the server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
    {
        perror("connect");
        return 1;
    }

    // receive the current time from the server
    char buf[64];
    int n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) 
    {
        perror("recv");
        return 1;
    }

    // print the current time
    cout << buf << endl;

    // close the socket
    close(sockfd);

    return 0;
}