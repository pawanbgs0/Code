#include "tcp.h"

tcp::tcp(string ip, string port)
{
    this->ipAddress = &ip[0];
    this->portNumber = &port[0];
}

void tcp::server()
{
    int sd, cliLen, newSd, n;
	struct sockaddr_in servAddr, cliAddr;
	char buffer[MAX_MSG];
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(ipAddress); // ined_addr -> converts ip address into 32 bit binary number
	servAddr.sin_port = htons(atoi(portNumber)); // atoi -> string to integer. // -> htones -> works only on int, (host to tcp short) converts into 16-bit binary number
	memset(&(servAddr.sin_zero), '\0', 8); // zero the rest of the struct.sin_zero

	sd = socket(AF_INET, SOCK_STREAM, 0);

	if (sd > 0)
		printf("Successfully created stream socket.\n");

	bind(sd, (struct sockaddr*)&servAddr, sizeof(servAddr));
	printf("Bound local port successfully\n");

	listen(sd, 5); // server is listening connection request and 5 is the number of clients allowed

	while(1)
	{
		printf("Waiting for coient connection on TCP Port %u\n", atoi(portNumber));

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
		}while(abs(strcmp(buffer, "quit")));

		/* close client connection*/
		printf("closing connection with host [IP %s, TCP port %d]\n", inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port));

		close(newSd);
	}
}

void tcp::client()
{
    int sd, cliLen, newSd, n;
	struct sockaddr_in servAddr, cliAddr;
	string message;
	char* encodedMessage;
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(ipAddress); // ined_addr -> converts ip address into 32 bit binary number
	servAddr.sin_port = htons(atoi(portNumber)); // atoi -> string to integer. // -> htones -> works only on int, (host to tcp short) converts into 16-bit binary number
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
        cin >> message;

		// Converting into huffman binary code
		Huffman h1(message);
		string huffMessage;

		h1.calculate_tree();
		huffMessage = h1.finalMessageCode();

		// encrypting the converted huffman binary code

		vector<unsigned char> key = {'s', 'e', 'c', 'r', 'e', 't', 'k', 'e', 'y'}; // initially make a default key, will modify it later to generate random key
		vector<unsigned char> huffman_data(huffMessage.begin(), huffMessage.end());
		
		vector<unsigned char> encrypted_data = aes_encrypt(huffman_data, key);

		encodedMessage = convert(encrypted_data);

        send(sd, encodedMessage, strlen(encodedMessage) + 1, 0);
        printf("data sent (%s)\n", encodedMessage);
    } while (strcmp(encodedMessage, "quit"));
    
	
	printf("closing connection with the server\n");
    close(sd);
}