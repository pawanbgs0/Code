#include "tcp.h"

// use linker -lssl -lcrypto while complie to link encodedMessage file functions

int main()
{
    string ip;
    string port;

    cout << "Enter the IP Address: ";
    cin >> ip;

    cout << "Enter the Port Number: ";
    cin >> port;

    tcp t(ip, port);
    t.client();


    return 0;
}