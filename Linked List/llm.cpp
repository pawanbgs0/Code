#include "ll.h"

int main()
{
    Linked_List ll;
    Node* temp;

    ll.append(1);
    ll.append(2);
    ll.append(2);
    ll.append(2);
    ll.append(3);
    ll.append(3);
    ll.append(4);
    ll.append(7);
    // ll.append(1);

    ll.removeDuplicates();
    ll.traverse();


    return 0;
}