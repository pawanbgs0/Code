#include "disjointSet.h"

DisjointSet::DisjointSet()
{
    this->rank.resize(0);
    this->parent.resize(0);
}

DisjointSet::DisjointSet(int no_vertices)
{
    this->rank.resize(no_vertices + 1, 0); // +1 if the graph is 1 based indexing so it works for both
    this->parent.resize(no_vertices + 1);
    this->size.resize(no_vertices+ 1, 1);

    for (int i = 0; i <= no_vertices; i++)
    {
        parent[i] = i;
    }
}

int DisjointSet::find_ultimate_parent(int node)
{
    if (parent[node] == node)
        return node;
        
    return parent[node] = find_ultimate_parent(parent[node]); // Along with path compression
}

void DisjointSet::union_by_rank(int nodeU, int nodeV)
{
    int ult_parentU = find_ultimate_parent(nodeU);
    int ult_parentV = find_ultimate_parent(nodeV);

    if (ult_parentU == ult_parentV)
        return; // as they belong to same component

    if (this->rank[ult_parentU] < this->rank[ult_parentV])
        this->parent[ult_parentU] = ult_parentV;
    
    else if (rank[ult_parentV] < rank[ult_parentU])
        parent[ult_parentV] = ult_parentU;

    else
    {
        parent[ult_parentV] = ult_parentU;
        rank[ult_parentU]++; // when both are equal attach to anyone but the parent's rank will increase
    }
}

void DisjointSet::union_by_size(int nodeU, int nodeV)
{

    int ult_parentU = find_ultimate_parent(nodeU);
    int ult_parentV = find_ultimate_parent(nodeV);

    if (ult_parentU == ult_parentV)
        return; // as they belong to same component

    if (size[ult_parentU] < size[ult_parentV])
    {
        parent[ult_parentU] = ult_parentV;
        size[ult_parentV] += size[ult_parentU];
    }
    else 
    {
        parent[ult_parentV] = ult_parentU;
        size[ult_parentU] += size[ult_parentV];
    }
}
