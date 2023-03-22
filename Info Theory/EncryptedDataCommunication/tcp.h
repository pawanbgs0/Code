#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "huff.h"
#include "endEncrypt.h"


#define MAX_MSG 100

class tcp
{
    char* ipAddress;
    char* portNumber;
    public:
        tcp(string ip, string port);
        void server();
        void client();
};