#include "crc.h"

int main()
{
    string message = "1100000001111";
    string tail = "10101";

    // string message, tail;

    // cout << "Enter the message bits: ";
    // cin >> message;

    // cout << "Enter the tail bits: ";
    // cin >> tail;

    string crc = getCRC(message, tail);

    cout << "crc is " << crc << endl;

    bool res = isCorrect(message + crc, tail);

    if (res)
        cout << "No error found!" << endl;
    else
        cout << "Error Found!" << endl;

    return 0;
}