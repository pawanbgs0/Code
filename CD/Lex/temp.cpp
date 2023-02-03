#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 10; j < 15; j++)
        {
            if (j == 12)
                break;
            cout << j << " ";
        }
    }
}