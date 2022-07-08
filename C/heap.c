#include "heap.h"

void swap_item(item *a, item *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void init(Heap *hp)
{
    int given_size;

    printf("Enter the size of Heap: ");
    scanf("%d", &given_size);

    hp->size = given_size;
    hp->arr = (item*)malloc(given_size * sizeof(Heap));
    hp->index = -1;
}

void add_max_heap(Heap* hp, item value)
{
    int parent, child;

    if (hp->index == hp->size - 1)
        return;
    
    hp->index = hp->index + 1;
    hp->arr[hp->index] = value;

    child = hp->index;

    while (child != 0)
    {
        parent = (child - 1) / 2;
        if (hp->arr[child] > hp->arr[parent])
            swap_item(&(hp->arr[parent]), &(hp->arr[child]));

        child = parent;
    }
}

void display_heap(Heap hp)
{
    int i;
    for (i = 0; i < hp.size; i++)
    {
        printf("%d ", hp.arr[i]);
    }
}

item delete_heap(Heap *hp)
{
    item res;
    int parent, child;

    if (hp->index == -1)
        return -999;

    res = hp->arr[0];

    hp->arr[0] = hp->arr[hp->size - 1];
    hp->index--;

    parent = 0;
    do 
    {
        child = 2 * parent + 1;

        if (child > hp->index)
            break;

        if (child < hp->index && hp->arr[child] < hp->arr[child + 1])
            child++;
        
        if (hp->arr[parent] < hp->arr[child])
        {
            swap_item(&(hp->arr[parent]), &(hp->arr[child]));
            parent = child;
        }
        else 
            break;
    }while (child <= hp->index);

    return res;
}