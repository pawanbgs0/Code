#include "tcp.h"

int main()
{
    string ip;
    string port;

    cout << "Enter the IP Address: ";
    cin >> ip;

    cout << "Enter the Port Number: ";
    cin >> port;

    tcp t(ip, port);
    t.server();


    return 0;
}