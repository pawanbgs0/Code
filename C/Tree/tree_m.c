#include "tree.h"

int main()
{
    Node* root = NULL;

    // root = create_node(16);
    // root->left = create_node(53);
    // root->right = create_node(45);

    // root->left->left = create_node(1);
    // root->left->right = create_node(2);

    // root->right->right = create_node(19);


    // preorder(root);
    // levelorder(root);

    // add_bst(&root, 48);
    // add_bst(&root, 36);
    // add_bst(&root, 42);
    add_bst(&root, 3);
    add_bst(&root, 2);
    add_bst(&root, 1);
    right_rotate(&root);

    preorder(root);
    return 0;
}