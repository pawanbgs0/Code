#include "tree.h"

int main()
{
    Tree btree;

    vector<int> preorder = {1, 2, 4, 5, 7, 3, 6, 8};
    vector<int> inorder = {4, 2, 7, 5, 1, 8, 6, 3};
    // vector<int> preorder = {1, 2, 4, 5, 6, 10, 3, 9, 10};
    // vector<int> inorder = {4, 5, 6, 2, 10, 1, 9, 3, 10};
    
    // btree.add_left(2);
    // btree.add_right(6);
    // btree.preorder();
    // btree.inorder();
    // btree.postorder();
    // btree.levelorder();
    // btree.zig_zag();

    btree.PreInTree(preorder, inorder);
    // btree.preorder();
    // btree.inorder();
    btree.boundryPrint();
    btree.vertical_traversal();
    btree.top_view();
    btree.bottom_view();
    btree.right_view();
    btree.left_view();
    return 0;
}