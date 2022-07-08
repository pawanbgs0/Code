#include "fcfs_h.h"

double fcfs(vector<char> process, vector<int> btime)
{
    vector<int> Ctime(process.size(), 0);
    vector<int> Wtime(process.size(), 0);
    int sum = 0;

    Ctime[0] = btime[0];

    for (int i = 1; i < process.size(); i++)
    {
        Ctime[i] = Ctime[i - 1] + btime[i];
    }

    for (int i = 0; i < process.size(); i++)
    {
        Wtime[i] = Ctime[i] - btime[i];
    }

    for (int i = 0; i < process.size(); i++)
    {
        sum += Wtime[i];
    }

    return sum / (process.size() * 1.0);
}