#include "huff.h"

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

Node::Node(int value)
{
    this->data = value;
    this->left = NULL;
    this->right = NULL;
}

Huffman::Huffman()
{
    this->TreeRoot = NULL;
}

Huffman::Huffman(string input)
{
    this->TreeRoot = NULL;
    this->input = input;
}

void Huffman::freq_manager()
{
    for (int i = 0; i < this->input.size() - 1; i++) // -1 is to remove the duplicacy of last character as the last character is read twice while reading from file.
    {
        frequency[this->input[i]]++;
    }

    for (auto it = frequency.begin(); it != frequency.end(); it++)
    {   
        char charac = it->first;
        int freq = it->second;

        this->queue.push(new Node(charac, freq));
    }
}

void Huffman::calculate_tree()
{
    Node* one, *two, *sum;

    freq_manager();

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
    code_generator_helper(this->TreeRoot, "");
}


void Huffman::code_generator_helper(Node* TreeRoot, string code)
{
    if (TreeRoot == NULL)
        return;

    if (TreeRoot->left == NULL && TreeRoot->right == NULL)
    {
        // cout << TreeRoot->character << " \t\t " << code << endl;
        this->codemap[TreeRoot->character] = code;
    }
    
    code_generator_helper(TreeRoot->left, code + "0");
    code_generator_helper(TreeRoot->right, code + "1");
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

vector<string> Huffman::getCodes()
{
    vector<string> res;

    for (auto &it: codemap)
    {
        res.push_back(it.second);
    }

    return res;
}


void Huffman::display_freq()
{
    for (auto &it: frequency)
    {
        cout << it.first << " " << it.second << endl;
    }
}


void Huffman::display_code()
{
    string code;


    cout << endl << "Characters: \t Code: " << endl;

    for (auto it = this->codemap.begin(); it != codemap.end(); it++)
    {
        cout << it->first << "\t\t" << it->second << endl;
    }
} 

string Huffman::finalMessageCode()
{
    string res;

    for (int i = 0; i < input.size(); i++)
    {
        res += codemap[input[i]];
    }

    return res;
}

string Huffman::decodeMessage(string messageCode)
{
    string res;
    Node* current = TreeRoot;

    if (TreeRoot == NULL)
        return "";

    for (int i = 0; i < messageCode.size(); i++)
    {
        char character = messageCode[i];

        if (current->left == NULL && current->right == NULL)
        {
            res += current->character;
            current = TreeRoot;
        }

        if (messageCode[i] == '0')
            current = current->left;

        else if (messageCode[i] == '1')
            current = current->right;
        
        else
        {
            cout << "Message is not properly encoded." << endl;
            return "";
        }
    }
    return res;
}