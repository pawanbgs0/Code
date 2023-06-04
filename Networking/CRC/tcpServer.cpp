// TCP Socket Programming (reciever)

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "crc.h"

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
    string tail = "1101";
	
	if (argc < 3) // name of program, ip address, port number
	{
		printf("Input error\n");
		exit(0);
	}
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]); // ined_addr -> converts ip address into 32 bit binary number
	servAddr.sin_port = htons(atoi(argv[2])); // atoi -> string to integer. // -> htones -> works only on int, (host to network short) converts into 16-bit binary number
	memset(&(servAddr.sin_zero), '\0', 8); // zero the rest of the struct.sin_zero

	sd = socket(AF_INET, SOCK_STREAM, 0);

	if (sd > 0)
		printf("Successfully created stream socket.\n");

	bind(sd, (struct sockaddr*)&servAddr, sizeof(servAddr));
	printf("Bound local port successfully\n");

	listen(sd, 5); // server is listening connection request and 5 is the number of clients allowed

	while(1)
	{
		printf("Waiting for coient connection on TCP Port %u\n", atoi(argv[2]));

		/*wait for the client connection*/
		cliLen = sizeof(cliAddr);
		newSd = accept(sd, (struct sockaddr *)&cliAddr, (socklen_t*)&cliLen);
		printf("recieved connection from host (IP %s, TCP Port %d): %s\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port), buffer);

		do 
		{
			memset(buffer, 0, MAX_MSG);
			n = recv(newSd, buffer, MAX_MSG, 0);
			buffer[n] = '\n';
			printf("recieved from host [IP %s, TCP port %d] : %s\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port), buffer);

            string msg;

            for (int i = 0; i < strlen(buffer) - 2; i++)
            {
                msg += buffer[i];
                // cout << buffer[i] << " ";
            }

            bool res = isCorrect(msg, tail);

            if (res)
                cout << "The message recieved is correct." << endl;
            // else
                // cout << "The message recieved is incorrect." << endl;

		}while(abs(strcmp(buffer, "quit")));

		/* close client connection*/
		printf("closing connection with host [IP %s, TCP port %d]\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port));

		close(newSd);
	}
	
	return 0;	
}