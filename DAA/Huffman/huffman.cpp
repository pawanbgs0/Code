#include "huffman.h"

Node::Node()
{
    this->left = NULL;
    this->right = NULL;
}

Node::Node(char character, int frequency)
{
    this->left = NULL;
    this->right = NULL;
    this->character = character;
    this->freq = frequency;
}


istream &operator>>(istream &in, Huffman &ob)
{

    cout << "Enter the total number of characters: ";
    in >> ob.size;
    
    for (int i = 0; i < ob.size; i++)

    {   char charac;
        int freq;

        cout << endl << "Enter the Charachter: ";
        in >> charac;
        cout << "Enter the Frequency of " << charac << ": " ;
        in >> freq;

        ob.queue.push(new Node(charac, freq));
    }

    return in;
}


Huffman::Huffman()
{
    this->TreeRoot = NULL;
    this->size = 0;
}

Huffman::Huffman(int size)
{
    this->TreeRoot = NULL;
    this->size = size;
}


void Huffman::calculate_tree()
{
    Node* one, *two, *sum;

    while (this->queue.size() != 1)
    {
        one = this->queue.top();
        this->queue.pop();
        
        two = this->queue.top();
        this->queue.pop();

        sum = new Node('$', one->freq + two->freq);
        sum->left = one;
        sum->right = two;

        this->queue.push(sum);
    }

    this->TreeRoot = queue.top();
}


void Huffman::print_queue()
{
    priority_queue<Node*, vector<Node*>, compare> current = this->queue;

    cout << endl << "Characters: \t Frequency: " << endl;

    while (!current.empty())
    {
        Node* temp = current.top();
        current.pop();

        cout << temp->character << " \t\t " << temp->freq << endl;
    }

}


void Huffman::print_code_helper(Node* TreeRoot, string code)
{
    if (TreeRoot == NULL)
        return;

    if (TreeRoot->character != '$')
    {
        cout << TreeRoot->character << " \t\t " << code << endl;
        this->codemap[TreeRoot->character] = code;
    }
    
    print_code_helper(TreeRoot->left, code + "0");
    print_code_helper(TreeRoot->right, code + "1");
}

ostream &operator<<(ostream &out, Huffman &ob)
{
    string code;

    out << endl << "Characters: \t Code: " << endl;

    ob.print_code_helper(ob.TreeRoot, code);

    return out;
}

string Huffman::encode(string w)
{
    string res;

    for (int i = 0; i < w.size(); i++)
    {
        res += this->codemap[w[i]];
    }

    return res;
}

void Huffman::calc_freq(string w)
{
    for (int i = 0; i < w.size(); i++)
    {
        this->frequency[w[i]]++;
    }
}