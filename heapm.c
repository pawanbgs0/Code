#include "heap_prac.h"

int main()
{
    heap h;
    init(&h,4);

    max_insert(&h,2);
    max_insert(&h,4);
    max_insert(&h,6);
    max_insert(&h,8);
    display(&h);
    printf("\n");
    printf("%d ",max_delete(&h));
    printf("%d ",max_delete(&h));
    printf("%d ",max_delete(&h));
    printf("%d ",max_delete(&h));

    printf("\n");

    min_insert(&h,2);
    min_insert(&h,4);
    min_insert(&h,6);
    min_insert(&h,8);
    display(&h);
    printf("\n");
    printf("%d ",min_delete(&h));
    printf("%d ",min_delete(&h));
    printf("%d ",min_delete(&h));
    printf("%d ",min_delete(&h));

    return 0;


}