#include "kosaRaju.h"

vector<vector<int>> buildAdjList(int noNodes, int noEdges)
{
    vector<vector<int>> adjList(noNodes, vector<int>(0));

    for (int i = 0; i < noEdges; i++)
    {
        int from;
        int to;

        cout << "From Node: ";
        cin >> from;

        cout << "To Node: ";
        cin >> to;

        adjList[from].push_back(to);
    }

    return adjList;
}


void DFS(int node, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &res)
{
    visited[node] = true;
    res.push_back(node);

    for (int i = 0; i < adjList[node].size(); i++)
    {
        if (!visited[adjList[node][i]])
            DFS(adjList[node][i], adjList, visited, res);
    }
}

void topoDFS(int node, vector<vector<int>> &adjList, vector<int> &visited, stack<int> &st)
{
    visited[node] = true;

    for (int i = 0; i < adjList[node].size(); i++)
    {
        if (!visited[adjList[node][i]])
            topoDFS(adjList[node][i], adjList, visited, st);
    }

    st.push(node);
}

vector<vector<int>> reverseAdjList(vector<vector<int>> &adjList)
{
    vector<vector<int>> res(adjList.size(), vector<int> (0));

    for (int i = 0; i < adjList.size(); i++)
    {
        int from = i;

        for (int j = 0; j < adjList[from].size(); j++)
        {
            int to = adjList[from][j];

            res[to].push_back(from);
        }
    }

    return res;
}

vector<vector<int>> stronglyConnectedComponents(vector<vector<int>> &adjList)
{
    vector<vector<int>> revAdjList;
    vector<int> visited(adjList.size(), 0);
    stack<int> topoStack;
    vector<vector<int>> res;

    topoDFS(0, adjList, visited, topoStack); // step 1 -> sort on the basis of coming time
    
    revAdjList = reverseAdjList(adjList); // step 2 -> Transpose the graph, i.e. reverse the edges of List

    vector<int> visitedDFS(adjList.size(), 0);
    while (!topoStack.empty())
    {
        int node = topoStack.top();
        topoStack.pop();

        if (visitedDFS[node])
            continue;

        vector<int> dfsItems;
        DFS(node, revAdjList, visitedDFS, dfsItems);

        res.push_back(dfsItems);
    }

    return res;
}