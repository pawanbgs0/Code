#include <bits/stdc++.h>
using namespace std;

class Node;
class Linked_List;

class Data
{
    char processId;
    int processSize;
    public:
        Data();
        Data(char processId, int processSize);
        Data(const Data &ob);
        ~Data();
        friend Node;
        friend Linked_List;
};

class Node
{
    Node* next;
    Node* prev;
    Data data;
    public:
        Node();
        Node(Data value);
        Node(const Node &ob);
        ~Node();
        friend Linked_List;
};

class Linked_List
{
    Node* head;
    Node* tail;
    public:
        Linked_List();
        Linked_List(Data value);
        Linked_List(const Linked_List &ob);
        // ~Linked_List();
        void append_end(Data value);
        void append_begin(Data value);
        void append_after(Node* pos, Data value);
        void append_before(Node* pos, Data value);
        void traverse_next();
        void traverse_back();
        void delete_end();
        void delete_begin();
        void delete_after(Node* pos);
        void delete_before(Node* pos);
        Node* search_by_id(Data key);
        Node* search_by_data(Data key);
        Node* search_by_pos(int pos);
};