#include <bits/stdc++.h>
using namespace std;


class Binary_Tree;

class Node
{
    public:
    Node* left;
    Node* right;
    int data;
    // bool used;

    public:
        Node();
        Node(int value);
        friend Binary_Tree;
};

class Binary_Tree
{
    public:
    Node* root;
    vector<string> input;
    vector<string> discarded;
    int level;

    void deleteNodes(Node* ptroot);
    public:
        Binary_Tree();
        void takeInput();
        void buildFullTree();
        void levelOrder();
        void buildValidTree();
        void deleteExtraNodes();
        string serialize();
};