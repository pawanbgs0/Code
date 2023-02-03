#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node* link[26];
    int endWith;
    int prefixCount;

    public:
        Node()
        {
            this->endWith = 0;
            this->prefixCount = 0;
        }

        bool doesContain(char key)
        {
            if (this->link[key - 'a'] != NULL)
                return true;

            return false;
        }

        void put(char ch, Node* refNode)
        {
            this->link[ch - 'a'] = refNode;
        }

        Node* get(char ch)
        {
            return this->link[ch - 'a'];
        }

        void setEnd()
        {
            this->endWith++;
        }

        bool isEnd()
        {
            return this->endWith > 0;
        }

        void increasePreifxCount()
        {
            this->prefixCount += 1;
        }

        int wordCount()
        {
            return this->endWith;
        }

        int getPrefixCount()
        {
            return this->prefixCount;
        }

        void reducePrefix()
        {
            this->prefixCount--;
        }

        void reduceEnd()
        {
            this->endWith--;
        }
};




class Trie{
    Node* root;
    public:

    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node* current = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!current->doesContain(word[i]))
            {
                current->put(word[i], new Node());
            }
            
            current = current->get(word[i]);
            current->increasePreifxCount();
        }

        current->setEnd();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node* current = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (current->doesContain(word[i]))
                current = current->get(word[i]);
            else
                return 0;
        }

        return current->wordCount();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node* current = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (current->doesContain(word[i]))
                current = current->get(word[i]);
            else
                return 0;
        }

        return current->getPrefixCount();
    }

    void erase(string &word)
    {
        // Write your code here.
        Node* current = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (current->doesContain(word[i]))
            {
                current = current->get(word[i]);
                current->reducePrefix();
            }
            else
                return;
        }

        current->reduceEnd();

    }
};
