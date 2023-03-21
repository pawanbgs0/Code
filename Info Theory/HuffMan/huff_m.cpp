#include "huff.h"

int main(int argc, char *argv[])
{
    Huffman h1;
    Binary_Tree t;
    vector<string> input;

    h1.take_input(argv[1]);
    h1.calculate_tree();
    h1.display_freq();
    h1.display_code();

    input = h1.getCodes();

    t.takeInput(input);
    t.buildFullTree();
    
    t.buildValidTree();
    t.levelOrder();

    string temp = h1.finalMessageCode();
    cout << temp << endl;
    cout << h1.decodeMessage(temp) << endl;

    return 0;
}
