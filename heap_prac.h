#include<stdio.h>
#include<stdlib.h>
#define item int
typedef struct st{

    int rear;
    item * arr;
    int size;
}heap;

void init(heap * h,int size);
void swap(item * a, item * b);
void max_insert(heap * h,item val);
item max_delete(heap * h);
void min_insert(heap * h,item val);
item min_delete(heap * h);
void display(heap * h);
