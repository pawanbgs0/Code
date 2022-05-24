#include <bits/stdc++.h>
using namespace std;

#define item int

class Tree;

class Node
{
    Node* left;
    Node* right;
    item data;
    public:
        Node();
        Node(item data);
        friend Tree;
};

class Tree
{
    Node* root;
    void preorder_helper(Node* ptroot);
    void inorder_helper(Node* ptroot);
    void postorder_helper(Node* ptroot);
    int max_depth_helper(Node* ptroot);
    Node* preInTree_helper(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& inorderIndex);
    void boundry_helper(Node* root, vector<int> &leaf); //to store leaf nodes
    bool is_symmetrical_helper(Node* left, Node* right);
    public:
        Tree();
        Tree(item value);
        void add_left(item value);
        void add_right(item value);
        void delete_left(Node* node);
        void delete_right(Node* node);
        void inorder();
        void preorder();
        void postorder();
        void levelorder();
        void preinpost();
        int max_depth();
        void zig_zag(); // push root, root data. If level is odd (pop front, add back right to left) else pop back add front left to right
        void PreInTree(vector<int> preorder, vector<int> inorder);
        void boundryPrint();
        void vertical_traversal();
        void top_view();
        void bottom_view();
        void right_view();
        void left_view();
        bool is_symmetrical();
};