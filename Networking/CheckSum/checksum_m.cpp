#include "checksum.h"

int main()
{
    string message = "10101110";

    // for (auto &it: res)
    // {
    //     cout << it << endl;
    // }

    cout << getNewMessage(message, 4);

    return 0;
}