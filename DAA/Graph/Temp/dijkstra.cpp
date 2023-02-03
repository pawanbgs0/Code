#include<bits/stdc++.h>
using namespace std;

#define v 9

int mindis(int dist[],bool spset[])
{
    int mini=INT_MAX,min_idx;
    for(int i=0;i<v;i++)
    {
        if(spset[i]==false && dist[i]<=mini)
        {
            mini=dist[i],min_idx=i;
        }
    }
    return min_idx;
}
void printsol(int dis[])
{
    cout<<"Vertex \t Distance from the source"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<" \t\t\t\t"<<dis[i]<<endl;
    }
}
void dijkstra(int graph[v][v],int src)
{
    int dist[v];
    bool spset[v];
    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX,spset[i]=false;
    }
    dist[src]=0;
    for(int i=0;i<v-1;i++)
    {
        int u=mindis(dist,spset);
        spset[u]=true;
        for(int j=0;j<v;j++)
        {
            if((!spset[j]) && (graph[u][j]) && (dist[u]!=INT_MAX) && (dist[u]+graph[u][j]<dist[j]))
            {
                dist[j]=dist[u]+graph[u][j];
            }
        }
    }
    printsol(dist);
}

int main()
{
    int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph,0);
    return 0;
}