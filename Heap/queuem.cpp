#include "queue.h"

int main()
{
    Queue line(1);
    

    line.push(5);
    line.push(10);
    line.push(15);
    line.push(20);
    line.push(25);

    cout << line.top() << endl;
    line.pop();
    cout << line.top() << endl;
    cout << line.top() << endl;
    cout << line.top() << endl;

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << line.top() << " ";
    //     line.pop();
    // }

    return 0;
}