// TCP Socket Programming

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_MSG 100

/* 3 phases in the tcp/ip connections
	-> connection establishment
	-> data transfer
	-> connection termination
*/


/* socket(int family, int type, int protocol) -> defines protocol and returns socket descriptor
	if the return is +ve that means the protocol was defined correctly.

	AF_INET -> Internet Protocols (Address Family)

	SOCK_STREAM -> Stream Socket (type {connection oriented or connection less})

	0 -> As only one protocol is available for each family and type. */

/*
	int bind(int sd, struct sockaddr *myaddr, int addrelen);
	
	sd (socked descriptor) -> it is the return of socket function.
	myaddr: it is a pointer to an address structure containing local IP address & Port no.
		struct sockaddr_in -> for tcp model
	addrlen: it is the size of address structure
*/

int main(int argc, char *argv[])
{
	int sd, cliLen, newSd, n;
	struct sockaddr_in servAddr, cliAddr;
	char buffer[MAX_MSG];
	
	if (argc < 3) // name of program, ip address, port number
	{
		printf("Input error\n");
		exit(0);
	}
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]); // ined_addr -> converts ip address into 32 bit binary number
	servAddr.sin_port = htons(atoi(argv[2])); // atoi -> string to integer. // -> htones -> works only on int, (host to network short) converts into 16-bit binary number
	memset(&(servAddr.sin_zero), '\0', 8); // zero the rest of the struct.sin_zero

    cliAddr.sin_family = AF_INET;
    cliAddr.sin_addr.s_addr = INADDR_ANY;
    cliAddr.sin_port = htons(0);

	sd = socket(AF_INET, SOCK_STREAM, 0);

	if (sd > 0)
		printf("Successfully created stream socket.\n");

	/*connect to server*/
    connect(sd, (struct sockaddr *)&servAddr, sizeof(servAddr));
    printf("connected to server successfully\n");

	/*send data to server*/
    do
    {
        printf("Enter string to send to server: ");
        scanf("%s", buffer);

        send(sd, buffer, strlen(buffer) + 1, 0);
        printf("data sent (%s)\n", buffer);
    } while (strcmp(buffer, "quit"));
    
	
	printf("closing connection with the server\n");
    close(sd);

	return 0;	
}
