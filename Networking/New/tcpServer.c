// TCP Socket Programming

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "parity.h"

#define MAX_MSG 100

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
		newSd = accept(sd, (struct sockaddr *)&cliAddr, &cliLen);
		printf("recieved connection from host (IP %s, TCP Port %d): %s\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port), buffer);

		do 
		{
			memset(buffer, 0, MAX_MSG);
			n = recv(newSd, buffer, MAX_MSG, 0);
			buffer[n] = '\n';
			printf("recieved from host [IP %s, TCP port %d] : %s\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port), buffer);

			if (isError(buffer, strlen(buffer)))
				printf("Error Found");

			else
				printf("Error not found");
		}while(abs(strcmp(buffer, "quit")));

		/* close client connection*/
		printf("closing connection with host [IP %s, TCP port %d]\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port));

		close(newSd);
	}
	
	return 0;	
}
