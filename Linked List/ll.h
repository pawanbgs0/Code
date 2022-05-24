#include <bits/stdc++.h>
using namespace std;

#define item int

class Linked_List;

class Node
{
    Node* next;
    item data;
    public:
        Node();
        Node(item value);
        friend Linked_List;
};

class Linked_List
{
    Node* head;
    public:
        Linked_List();
        Linked_List(item value);
        void append(item value);
        void traverse();
        void addbeg(item value);
        Node* searchbykey(item key);
        Node* searchbypos(int pos);
        void addinmidafter(Node *pos, item data);
        void delfirst();
        void dellast();
};