#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int no_vertices;
    int no_edges;
    vector<vector<int>> adj_list;
    public:
        Graph();
        void take_input();
};