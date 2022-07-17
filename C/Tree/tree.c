#include "tree.h"

void init_tree(Node** root)
{
    (*root)->left = NULL;
    (*root)->right = NULL;
}

Node* create_node(item value)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->right = NULL;
    temp->left = NULL;
    temp->data = value;

    return temp;
}

void preorder(Node* root)
{
    if (root == NULL)
        return;
    
    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (root == NULL)
        return;
    
    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
        return;
    
    postorder(root->left);

    postorder(root->right);

    printf("%d ", root->data);
}


// void levelorder(Node* root)
// {
//     queue line;
//     Node* temp;

//     init(&line, 7);

//     enqueue(&line, root);

//     while (!isEmpty(&line))
//     {
//         temp = dequeue(&line);

//         if (temp->left != NULL)
//             enqueue(&line, temp->left);
        
//         if (temp->right != NULL)
//             enqueue(&line, temp->right);

//         printf("%d ", temp->data);
//     }
// }

int max(int a, int b)
{
    if (a > b)
        return a;
    
    return b;
}


int depth(Node* root)
{
    if (root == NULL)
        return 0;
    
    int left = 1 + depth(root->left);
    int right = 1 + depth(root->right);

    return max(left, right);
}

void add_bst(Node **root, item value)
{
    if ((*root) == NULL)
    {
        *root = create_node(value);
        return;
    }

    if (value < (*root)->data)
        add_bst(&(*root)->left, value);
    
    if (value > (*root)->data)
        add_bst(&(*root)->right, value);
}

void left_rotate(Node** root)
{
    Node* temp;

    if (*root == NULL || (*root)->right == NULL)
        return;

    temp = (*root)->right->left;
    (*root)->right->left = *root;
    *root = (*root)->right;
    (*root)->left->right = temp;
}

void right_rotate(Node** root)
{
    Node* temp;

    if (*root == NULL || (*root)->left == NULL)
        return;
    
    temp = (*root)->left->right;
    (*root)->left->right = *root;
    *root = (*root)->left;
    (*root)->left->right = temp;
}

void update_bfactor(Node** root)
{
    if (*root == NULL)
        return;
    
    (*root)->bfactor = depth((*root)->left) - depth((*root)->right);
}

void balance_node(Node** root)
{
    if (*root == NULL)
        return;
    
    update_bfactor(*root);

    if ((*root)->bfactor > 1)
    {
        if ((*root)->left->bfactor < 0) // Left-Right Rotation
        {
            left_rotate(&(*root)->left); //first root for LR
            right_rotate(*root); // 
        }
        else if ((*root)->bfactor < -1)
        {
            if ((*root)->right->bfactor < 0) // RL
            {
                right_rotate(&(*root)->right);
                left_rotate(*root);
            }
        }
        else 
            return;
    }
}

void insert(Node **root, int value)
{
    if (*root == NULL)
        *root = create_node(value);
    
    else 
    {
        if (value < (*root)->data)
            insert(&(*root)->left, value);
        
        else 
            insert(&(*root)->right, value);
        
        balance_node(root);
    }
}