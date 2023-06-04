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

    cliAddr.sin_family = AF_INET;
    cliAddr.sin_addr.s_addr = INADDR_ANY;
    cliAddr.sin_port = htons(0);

	sd = socket(AF_INET, SOCK_STREAM, 0);

	if (sd > 0)
		printf("Successfully created stream socket.\n");

	/*connect to server*/
    int value = connect(sd, (struct sockaddr *)&servAddr, sizeof(servAddr));

	if (value > 0)
    	printf("connected to server successfully\n");

	/*send data to server*/
    do
    {
        printf("Enter string to send to server: ");
        scanf("%s", buffer);

		char bit = generateParityBit(buffer, strlen(buffer));
		buffer[strlen(buffer)] = bit;

		printf("%s", buffer);

        send(sd, buffer, strlen(buffer) + 1, 0);
        printf("data sent (%s)\n", buffer);
    } while (strcmp(buffer, "quit"));
    
	
	printf("closing connection with the server\n");
    close(sd);

	return 0;	
}
