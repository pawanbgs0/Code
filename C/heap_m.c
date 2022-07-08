#include "heap.h"

int main()
{
    Heap h1;
    int size;
    
    init(&h1);
    add_max_heap(&h1, 2);
    add_max_heap(&h1, 1);
    add_max_heap(&h1, 3);
    add_max_heap(&h1, 4);
    add_max_heap(&h1, 6);
    add_max_heap(&h1, 5);
    add_max_heap(&h1, 7);
    add_max_heap(&h1, 8);

    // display_heap(h1);

    size = h1.size;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", delete_heap(&h1));
    }
    return 0;
}