#include <stdio.h>
#include <stdlib.h>

#define S 6 

int rank[S];
int parent[S];

int init_parent();
int find_parent();
int do_union();