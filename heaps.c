//heapify-->to get max/min heap
//this method is useful as it considers or make comparisons
//from the non leaf nodes and facilitates them instead of the leaf nodes

#include<stdio.h>
#include<stdlib.h>
void swap(int * a,int *b)
{
    int t;
    t=*b;
    *b=*a;
    *a=t;
}
void heapify(int *arr,int n)
{
    int i,parent,child;
    for(i=n-1;i>=0;--i)
    {
        parent=i;
        do{
            child=(2*parent)+1;
            if(child>=n)
                break;
            if(child<n-1 && arr[child]<arr[child+1])
                ++child;
            if(arr[parent]<arr[child])
            {
                swap(&arr[parent],&arr[child]);
                parent=child;
            }
            else
                break;
        }while(child<n);


    }
}
void  heapsort(int *arr,int n)
{
    heapify(arr,n);
    int i;
    for(i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i);
    }
}
void print_arr(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int size,*arr;
    printf("enter the no. of elements:");
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);

    }
    heapsort(arr,size);
    print_arr(arr,size);
    

    return 0;
}