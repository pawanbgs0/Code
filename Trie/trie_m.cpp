#include "trie.h"

int main()
{
    Trie t;

    t.insert("apple");
    t.insert("aps");
    t.insert("apxl");
    t.insert("bac");
    t.insert("bat");


    cout << t.hasPrefix("ap") << endl;
    cout << t.search("apxl") << endl;
    cout << t.hasPrefix("bal") << endl;
    cout << t.search("apx") << endl;
    return 0;
}