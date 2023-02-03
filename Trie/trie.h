#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node* links[26]; // assuming all as lowercase
    bool flag;

    public:
        Node();
        bool doesContain(char key); // checks if the current char is available in this particular node
        void put(char ch, Node *refNode); // put the reference node to the respective char
        Node* get(char ch); // return the refrence Node of char
        void setEnd(); // mark the flag of the node as true to indicate the end of word
        bool isEnd(); // checking if the end Node 
};

class Trie
{
    Node* root;

    public:
        Trie();
        void insert(string word);
        bool search(string word); // does the word exist in the Trie
        bool hasPrefix(string word); // check if the word is available as prefix
};