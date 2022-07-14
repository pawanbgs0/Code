#include <bits/stdc++.h>
using namespace std;

#define item int
#define S 8 //no of vertices

class Graph
{
    vector<vector<item>> adj_matrix;
    vector<vector<int>> edges;
    vector<bool> visited_bfs;
    vector<bool> visited_dfs;
    vector<int> adj_list[S];
    int no_edge;
    int no_vertex;

    public:
        Graph();
        Graph(int no_edge, int no_vertex);
        void undirected_adj();
        void undirected_adj_list();
        void bfs(int start_index);
        void bfs_comp(); // complicated not running
        void dfs(int start_index);
        bool helper_cycle_bfs(int startIndex);
        bool isCyclic_bfs();
        bool helper_cycle_dfs(int startIndex, int parent);
        bool isCyclic_dfs();
        bool is_bipartite_bfs(int startIndex, vector<int> &coloured);
        bool is_bipartit_bfs_component();
        bool detect_cycle_directed_dfs(vector<bool> &visited, vector<bool> &visited_dfs, int startIndex);
        bool detect_cycle_directed_dfs_comp();
        void topological_sort_dfs(vector<bool> &visited, int node, stack<item> &res);
        vector<int> topological_sort_dfs_comp();
        vector<item> topological_sort_bfs(); // kahn's algorithm
};