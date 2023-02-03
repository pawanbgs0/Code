#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    public:
        DisjointSet();
        DisjointSet(int no_vertices);
        int find_ultimate_parent(int node);
        void union_by_rank(int nodeU, int nodeV);
        void union_by_size(int nodeU, int nodeV);
};