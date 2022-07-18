#include <stdio.h>
#include <stdlib.h>

#define item int


typedef struct st
{
    item data;
    struct st* left;
    struct st* right;
    int bfactor;
}Node;

#define ITEM Node*

void init_tree(Node** root);
Node* create_node(item value);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);
void levelorder(Node* root);
int max(int a, int b);
int depth(Node* root);
void bst(Node** root, item value);
void add_bst(Node **root, item value);
void left_rotate(Node** root);
void right_rotate(Node** root);
void update_bfactor(Node** root);
void balance_node(Node** root);
void insert(Node **root, int value);