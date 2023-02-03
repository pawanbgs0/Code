#include <bits/stdc++.h>
using namespace std;

class Huffman;
struct compare;

class Node
{
    Node* left;
    Node* right;
    char character;
    int freq;

    public:
        Node();
        Node(char character, int freq);
        friend Huffman;
        friend compare;
        friend istream &operator>>(istream &in, Huffman &ob);
        friend ostream &operator<<(ostream &out, Huffman &ob);
};


struct compare 
{
    bool operator()(Node* one, Node* two)
    {
        return (one->freq > two->freq);
    }
};


class Huffman
{
    Node* TreeRoot;
    int size;
    priority_queue<Node*, vector<Node*>, compare> queue;
    unordered_map<char, string> codemap;
    unordered_map<char, int> frequency;

    void print_code_helper(Node* TreeRoot, string code);

    public:
        Huffman();
        Huffman(int size);
        void calculate_tree();
        void print_queue();
        friend istream &operator>>(istream &in, Huffman &ob);
        friend ostream &operator<<(ostream &out, Huffman &ob);
        string encode(string w);
        void calc_freq(string w);
};