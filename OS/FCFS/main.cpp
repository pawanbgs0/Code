#include "fcfs_h.h"

int main()
{
    vector<char> process = {'a', 'b', 'c'};
    vector<int> btime = {10, 5, 8};

    cout << fcfs(process, btime);
    return 0;
}