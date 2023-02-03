#include "disjointSet.h"

int main()
{
    DisjointSet ds(7);

    ds.union_by_size(1, 2);
    ds.union_by_size(2, 3);
    ds.union_by_size(4, 5);
    ds.union_by_size(6, 7);
    ds.union_by_size(5, 6);
    // ds.union_by_rank(3, 7);

    if (ds.find_ultimate_parent(3) == ds.find_ultimate_parent(7))
        cout << "They belong to same component.\n";
    else
        cout << "They don't belong to the same component.\n";


    ds.union_by_rank(3, 7);

    if (ds.find_ultimate_parent(3) == ds.find_ultimate_parent(7))
        cout << "They belong to same component.\n";
    else
        cout << "They don't belong to the same component.\n";

    return 0;
}