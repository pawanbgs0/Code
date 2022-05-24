#include <bits/stdc++.h>
using namespace std;

#define item int

class Heap
{
    item* arr;
    int maxSize;
    int curIndex;
    public:
        Heap();
        Heap(int maxSize);
        void maxheapify();
        bool is_full();
};

void enque(Heap* ptheap, item value)
{
    if (ptheap->is_full())
        return;

    ptheap->arr[++]
}
