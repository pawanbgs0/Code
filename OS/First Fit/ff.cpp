#include "ff.h"

Data::Data()
{
    this->processId = 'N';
    this->processSize = 0;
}

Data::Data(char processId, int processSize)
{
    this->processId = processId;
    this->processSize = processSize;
}

Data::Data(const Data &ob)
{
    this->processId = ob.processId;
    this->processSize = ob.processSize;
}

Data::~Data()
{
    this->processId = 0;
    this->processSize = 0;
}

Node::Node()
{
    this->prev = NULL;
    this->next = NULL;
}

Node::Node(Data value)
{
    this->prev = NULL;
    this->next = NULL;
    this->data = value;
}

Node::Node(const Node &ob)
{
    this->prev = ob.prev;
    this->next = ob.next;
    this->data = ob.data;
}

Node::~Node()
{
    delete next;
    delete prev;
}

Linked_List::Linked_List()
{
    this->head = NULL;
    this->tail = NULL;
}

Linked_List::Linked_List(Data value)
{
    Node* temp = new Node(value);
    this->head = temp;
    this->tail = temp;
}

Linked_List::Linked_List(const Linked_List &ob)
{
    this->head = ob.head;
    this->tail = ob.tail;
}

// Linked_List::~Linked_List()
// {
//     free(head);
//     free(tail);
// }

void Linked_List::append_end(Data value)
{
    Node* temp = new Node(value);

    if (this->head == NULL)
    {
        this->head = temp;
        this->tail = temp;
        return;
    }
    
    temp->prev = this->tail;
    tail->next = temp;
    this->tail = temp;
}

void Linked_List::append_begin(Data value)
{
    Node* temp = new Node(value);

    if (this->head == NULL)
    {
        this->head = temp;
        this->tail = temp;
        return;
    }

    temp->next = this->head;
    head->prev = temp;
    this->head = temp;
}

void Linked_List::append_after(Node* pos, Data value)
{
    Node* temp = new Node(value);

    if (this->head == NULL)
    {
        this->head = temp;
        this->tail = temp;
        return;
    }

    temp->prev = pos;
    temp->next = pos->next;
    pos->next->prev = temp;
    pos->next = temp;
}

void Linked_List::append_before(Node* pos, Data value)
{
    Node* temp = new Node(value);

    if (this->head == NULL)
    {
        this->head = temp;
        this->tail = temp;
        return;
    }

    temp->prev = pos->prev;
    temp->next = pos;

    if (pos->prev != NULL)
        pos->prev->next = temp;
    
    pos->prev = temp;
}

void Linked_List::traverse_next()
{
    Node* temp = this->head;

    while (temp != NULL)
    {
        cout << temp->data.processId << " " << temp->data.processSize << endl;
        temp = temp->next;
    }
}

void Linked_List::traverse_back()
{
    Node* temp = this->tail;

    while (temp != NULL)
    {
        cout << temp->data.processId << " " << temp->data.processSize << endl;
        temp = temp->prev;
    }
}

void Linked_List::delete_end()
{
    Node* temp;

    if (this->tail == NULL)
        return;
    
    temp = this->tail;
    tail = tail->prev;
    delete temp;
}

void Linked_List::delete_begin()
{
    Node* temp;

    if (this->head == NULL)
        return;
    
    temp = this->head;
    head = head->next;
    delete temp;
}

