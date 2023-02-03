#include "trie.h"

Node::Node()
{
    this->flag = false;
}

bool Node::doesContain(char key)
{
    if (links[key - 'a'] != NULL)
        return true;

    return false;
}

void Node::put(char ch, Node *refNode)
{
    this->links[ch - 'a'] = refNode;
}

Node* Node::get(char ch)
{
    return this->links[ch - 'a'];
}

void Node::setEnd()
{
    this->flag = true;
}

bool Node::isEnd()
{
    return this->flag;
}

Trie::Trie()
{
    this->root = new Node();
}

void Trie::insert(string word)
{
    Node* current = root;

    for (int i = 0; i < word.size(); i++)
    {
        if (!current->doesContain(word[i]))
        {
            current->put(word[i], new Node());
        }

        current = current->get(word[i]);
    }
    current->setEnd();
}

bool Trie::search(string word)
{
    Node* current = root;

    for (int i = 0; i < word.size(); i++)
    {
        if (current->doesContain(word[i]))
            current = current->get(word[i]);
        
        else
            return false;
    }

    return current->isEnd();
}

bool Trie::hasPrefix(string word)
{
    Node* current = root;

    for (int i = 0; i < word.size(); i++)
    {
        if (current->doesContain(word[i]))
            current = current->get(word[i]);

        else
            return false;
    }

    return true;
}