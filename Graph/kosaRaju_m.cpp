#include "kosaRaju.h"

int main()
{
    vector<vector<int>> adjList, scc;
    int noNodes, noEdges;

    cout << "Enter the number of Nodes: ";
    cin >> noNodes;

    cout << "Enter the number of Edges: ";
    cin >> noEdges;

    adjList = buildAdjList(noNodes, noEdges);

    cout << "AdjList: " << endl;
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << " -> ";
        for (auto &it: adjList[i])
            cout << it << " ";

        cout << endl;
    }

    scc = stronglyConnectedComponents(adjList);

    for (auto &it: scc)
    {
        for (auto &it2: it)
            cout << it2 << " ";

        cout << endl;
    }

    return 0;
}