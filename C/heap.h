#include <stdio.h>
#include <stdlib.h>

#define item int

typedef struct st
{
    item *arr;
    int size;
    int index;
}Heap;

void swap_item(item *a, item *b);
void init(Heap *hp);
void add_max_heap(Heap *hp, item value);
void display_heap(Heap hp);
item delete_heap(Heap *hp);