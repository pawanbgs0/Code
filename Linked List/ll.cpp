#include "ll.h"

Node::Node()
{
    this->next = NULL;
}

Node::Node(item value)
{
    this->next = NULL;
    this->data = value;
}

Linked_List::Linked_List()
{
    this->head = NULL;
}

Linked_List::Linked_List(item value)
{
    this->head = new Node(value);
}

void Linked_List::append(item value)
{
    Node* temp = this->head;

    if (this->head == NULL)
    {
        this->head = new Node(value);
    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(value);
    }
    
}

void Linked_List::traverse()
{
    Node* temp = this->head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Linked_List::addbeg(item value)
{
    Node* temp;

    if (this->head == NULL)
    {
        this->head = new Node(value);
    }

    else 
    {
        temp = new Node(value);
        temp->next = this->head;
        this->head = temp;
    }
}

Node* Linked_List::searchbykey(item key)
{
    Node* temp = this->head;

    if (this->head == NULL)
        return NULL;

    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;

        temp = temp->next;
    }
    return NULL;
}

Node* Linked_List::searchbypos(int pos)
{
    Node* temp = this->head;

    if (this->head == NULL)
        return NULL;

    for (int i = 1; i <= pos; i++)
    {
        if (i == pos)
            return temp;
        
        temp = temp->next;
    }
    return NULL;
}

void Linked_List::addinmidafter(Node* pos, item data)
{
    Node* temp;

    if (pos == NULL)
        return;

    temp = new Node(data);
    temp->next = pos->next;
    pos->next = temp;
}

void Linked_List::delfirst()
{
    Node* temp;

    if (this->head == NULL)
        return;
    
    if (this->head->next == NULL)
    {
        temp = this->head;
        this->head = NULL;
        delete temp;
        return;
    }

    temp = this->head;
    this->head = this->head->next;
    delete temp;
}

void Linked_List::dellast()
{
    Node* temp, *todelete;

    if (this->head == NULL)
        return;

    if (this->head->next == NULL)
    {
        temp = this->head;
        this->head = NULL;
        delete temp;
        return;
    }

    temp = this->head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}