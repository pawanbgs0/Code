#include<bits/stdc++.h>
using namespace std;
#define v 5
int minkey(int key[],bool mset[])
{
    int mini=INT_MAX,min_idx;
    for(int i=0;i<v;i++)
    {
        if(mset[i]==false && key[i]<mini)
        {
            mini=key[i],min_idx=i;
        }
    }
    return min_idx;
}
void printmst(int parent[],int graph[v][v])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < v; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
void primst(int graph[v][v])
{
    int parent[v];
    int key[v];
    bool mset[v];
    for(int i=0;i<v;i++)
    {
        key[i]=INT_MAX,mset[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<v-1;i++)
    {
        int u=minkey(key,mset);
        mset[u]=true;
        for(int j=0;j<v;j++)
        {
            if(graph[u][j] && mset[j]==false && graph[u][j]<key[j])
            {
                parent[j]=u,key[v]=graph[u][j];
            }
        }
    }
    printmst(parent,graph);
}
int main()
{
    int graph[v][v] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    primst(graph);
 
    return 0;
}