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
    int data;

    public:
        Node();
        Node(char character, int freq);
        Node(int value);
        friend Huffman;
        friend compare;
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
    unordered_map<char, int> frequency;
    string input; // collection of chars as a string taken input from the file.
    priority_queue<Node*, vector<Node*>, compare> queue; // min_heap to draw tree 
    unordered_map<char, string> codemap; // to store the code of different characters
    
    void freq_manager(); // counts the frequency and stores it in the min heap (queue)
    void code_generator_helper(Node* TreeRoot, string code);

    public:
        Huffman();
        Huffman(string input);
        void calculate_tree();
        vector<string> getCodes();
        // Display Part
            void print_queue();
            void display_code();
            void display_freq();

        string finalMessageCode();
        string decodeMessage(string messageCode);
};