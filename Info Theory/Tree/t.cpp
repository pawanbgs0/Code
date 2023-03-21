#include "t.h"

Node::Node()
{
    this->left = NULL;
    this->right = NULL;
    // this->used = false;
}

Node::Node(int value)
{
    this->left = NULL;
    this->right = NULL;
    this->data = value;
    // this->used = false;
}

Binary_Tree::Binary_Tree()
{
    this->root = NULL;
    this->level = 0;
}

void Binary_Tree::takeInput()
{
    int size;

    cout << "Enter the size of input: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string temp;
        cout << "Enter the input string " << i + 1 << ": ";
        cin >> temp;

        level = max(level, (int)temp.size());
        input.push_back(temp);
    }
}


void Binary_Tree::buildFullTree()
{
    queue<Node*> q;
    int count = 1;

    root = new Node(count++);
    // level--;
    q.push(root);

    while (level--)
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();

            // cout << temp->data << " ";
            temp->left = new Node(count++);
            temp->right = new Node(count++);

            // if (temp->left)
                q.push(temp->left);

            // if (temp->right)
                q.push(temp->right);
        }
    }
}

void Binary_Tree::levelOrder()
{
    queue<Node*> q;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}

void Binary_Tree::deleteNodes(Node* ptroot)
{
    queue<Node*> q;

    if (ptroot == NULL)
        return;

    q.push(ptroot);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp->left)
            q.push(temp->left);
        
        if (temp->right)
            q.push(temp->right);

        // temp->left = NULL;
        // temp->right = NULL;
        cout << temp->data << " deleted" << endl;
        delete temp;
    }
}


void Binary_Tree::buildValidTree()
{
    Node* ptroot = this->root;

    for (auto &it: this->input)
    {
        // cout << it << endl;
        ptroot = root;
        // root->used = true;

        for (int i = 0; i < it.size(); i++)
        {
            if (ptroot != NULL)
            {
                if (it[i] == '1')
                {
                    ptroot = ptroot->left;
                    // ptroot->used = true;
                    // cout << it[i] << "->" << ptroot->data << " ";
                }
                else
                {
                    ptroot = ptroot->right;
                    // ptroot->used = true;
                    // cout << it[i] << "->" << ptroot->data << " ";
                }
            }
            else 
            {
                discarded.push_back(it);
                break;
            }
            
        }
        if (ptroot != NULL)
        {
            // cout << "deleting after " << ptroot->data << endl;
            
            deleteNodes(ptroot->left);
            deleteNodes(ptroot->right);
            ptroot->left = NULL;
            ptroot->right = NULL;
        }
    }

    string treeString = serialize();

    ofstream outfile("levelOrder.txt");
    outfile << treeString;
    
    outfile.close();
}


string Binary_Tree::serialize() 
{
    queue<Node*> q;
    string res;

    if (root == NULL)
        return res;

    q.push(root);

    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();

        if(node == NULL)
            res += "#,";
        else
            res += to_string(node->data) + ',';

        if(node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
        
    }

    // cout << res << endl;
    return res;
}

// void Binary_Tree::deleteExtraNodes()
// {
    
// }