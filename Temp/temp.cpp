#include <bits/stdc++.h>
using namespace std;

long long int fibo(long long int n, vector<long long int> &visited)
{
    if (n <= 1)
        return n;

    if (visited[n] != -1)
        return visited[n];

    return visited[n] = fibo(n - 1, visited) + fibo(n - 2, visited);
}

int main()
{
    long long int num;

    cout << "Enter the value of Num: ";
    cin >> num;

    vector<long long int> visited(num + 1, -1);

    cout << fibo(num, visited) << endl;
}