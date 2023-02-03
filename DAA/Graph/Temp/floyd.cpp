#include<bits/stdc++.h>
using namespace std;
#define v 4
#define infi 99999
void printsol(int dist[][v]);
void floyd(int dist[][v])
{
    int i,j,k;
    for(k=0;k<v;k++)
    {
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                if(dist[i][j]>(dist[i][k]+dist[k][j]) && (dist[k][j]!=infi))
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    printsol(dist);
}
void printsol(int dist[][v])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == infi)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}
int main()
{
    int graph[v][v] = { { 0, 5, infi, 10 },
                        { infi, 0, 3, infi },
                        { infi, infi, 0, 1 },
                        { infi, infi, infi, 0 } };
    floyd(graph);
    return 0;
}