#include "stack.h"

int main()
{
    Stack bucket(4);

    bucket.push(5);
    bucket.push(10);
    bucket.push(15);
    bucket.push(20);

    for (int i = 0; i < 4; i++)
    {
        cout << bucket.top() << " ";
        bucket.pop();
    }
    cout << endl;


    return 0;
}