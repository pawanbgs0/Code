#include "heap.h"

Heap::Heap()
{
    this->arr = NULL;
    this->curIndex = 0;
}

Heap::Heap(int maxSize)
{
    this->maxSize = maxSize;
    this->curIndex = 0;
    this->arr = new item[this->maxSize];
}

void Heap::maxheapify()
{
    for (int i = 1; i < this->curIndex; i++)
    {
        int parent = i;
        int leftchild = 2 * i;
        int rightchild = (2 * i) + 1;

        if (rightchild < this->maxSize)
        {
            if (arr[leftchild] > arr[parent] && arr[leftchild] > arr[rightchild])
                swap(arr[leftchild], arr[parent]);
        
            if (arr[rightchild] > arr[parent] && arr[rightchild] > arr[leftchild])
                swap(arr[parent], arr[rightchild]);
        }
        else
            break;
        
    }
}