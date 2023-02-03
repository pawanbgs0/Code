#include "huffman.h"

int main()
{
    Huffman h1;
    string w = "Ram aam khata hai";
    cin >> h1;
    h1.calculate_tree();
    cout << h1;

    return 0;
}
