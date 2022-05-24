#include "ll.h"

int main()
{
    Linked_List ll1;
    Node* temp;

    for (int i = 1; i < 5; i++)
    {
        ll1.append(i);
    }

    ll1.traverse();

    ll1.addbeg(0);

    ll1.traverse();

    temp = ll1.searchbykey(2);
    ll1.addinmidafter(temp, 99);

    temp = ll1.searchbypos(4);
    ll1.addinmidafter(temp, 100);

    ll1.traverse();

    ll1.delfirst();
    ll1.traverse();

    ll1.dellast();
    ll1.traverse();

    return 0;
}