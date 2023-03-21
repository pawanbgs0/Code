#include <bits/stdc++.h>

using namespace std;

class Huffman;
struct compare;
class Binary_Tree;

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
        friend Binary_Tree;
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
        Huffman(string file_name_with_extension);
        void calculate_tree();
        vector<string> getCodes();
        // Display Part
            void print_queue();
            void display_code();
            void display_freq();

        void take_input(string input_file_name);
        string finalMessageCode();
        string decodeMessage(string messageCode);
        
};

class Binary_Tree
{
    public:
    Node* root;
    vector<string> input;
    vector<string> discarded;
    int level;

    void deleteNodes(Node* ptroot);
    public:
        Binary_Tree();
        void takeInput(vector<string> input);
        void buildFullTree();
        void levelOrder();
        void buildValidTree();
        void deleteExtraNodes();
        string serialize();
        
};