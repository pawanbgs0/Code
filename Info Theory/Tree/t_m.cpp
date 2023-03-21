#include "t.h"

int main()
{
    Binary_Tree t;

    t.takeInput();
    t.buildFullTree();
    
    t.buildValidTree();
    t.levelOrder();
    
    return 0;
}