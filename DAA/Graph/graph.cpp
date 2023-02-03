#include "graph.h"

Graph::Graph()
{
    this->no_edges = 0;
    this->no_vertices = 0;
}

void Graph::take_input()
{
    cout << "Enter the Number of Vertices";
    cin >> this->no_vertices;
    cout << "Enter the Number of Edges: ";
    cin >> this->no_edges;

    for (int i = 0; i < no_vertices; i++)
    {
        vector<int> temp;
        adj_list.push_back(temp);
    }

    for (int i = 0; i < this->no_edges; i++)
    {
        int source, dest;
        cout << "Enter the source: ";
        cin >> source;
        cout << "Enter the destination: ";
        cin >> dest;
        this->adj_list[source].push_back(dest);
        this->adj_list[dest].push_back(source);
    }
}