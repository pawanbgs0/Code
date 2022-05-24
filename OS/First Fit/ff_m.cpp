#include "ff.h"

int main()
{
    Data value('A', 5);
    Linked_List l1(value);

    l1.append_end(Data('B', 10));
    l1.append_begin(Data('Z', -100));
    l1.traverse_next();
    cout << endl;
    l1.traverse_back();

    return 0;
}