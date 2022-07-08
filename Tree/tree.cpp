#include "tree.h"

Node::Node()
{
    this->left = NULL;
    this->right = NULL;
}

Node::Node(item value)
{
    this->left = NULL;
    this->right = NULL;
    this->data = value;
}

Tree::Tree()
{
    this->root = NULL;
}

Tree::Tree(item value)
{
    Node* temp = new Node(value);
    this->root = temp;
}

void Tree::add_left(item value)
{
    Node* current = this->root;

    if (this->root == NULL)
    {
        Node* temp = new Node(value);
        this->root = temp;
    }
    else 
    {
        while (current->left != NULL)
        {
            current = current->left;
        }
        current->left = new Node(value);
    }
}

void Tree::add_right(item value)
{
    Node* current = this->root;

    if (this->root == NULL)
    {
        this->root = new Node(value);
    }
    else 
    {
        while (current->right != NULL)
        {
            current = current->right;
        }
        current->right = new Node(value);
    }
}


void Tree::delete_left(Node* node)
{
    if (node->left == NULL)
        return;

    else 
    {
        node->left = NULL;
        delete node->left;
    }
}

void Tree::delete_right(Node* node)
{
    if (node->right == NULL)
        return;

    else 
    {
        node->right = NULL;
        delete node->right;
    }
}

void Tree::preorder_helper(Node* ptroot)
{
    if (ptroot == NULL)
        return;

    cout << ptroot->data << " ";

    preorder_helper(ptroot->left);
    preorder_helper(ptroot->right);
}

void Tree::inorder_helper(Node* ptroot)
{
    if (ptroot == NULL)
        return;

    inorder_helper(ptroot->left);

    cout << ptroot->data << " ";

    inorder_helper(ptroot->right);
}


void Tree::postorder_helper(Node* ptroot)
{
    if (ptroot == NULL)
        return;

    postorder_helper(ptroot->left);
    postorder_helper(ptroot->right);

    cout << ptroot->data << " ";
}

void Tree::preorder()
{
    Node* temp = this->root;

    preorder_helper(temp);
    cout << endl;
}

void Tree::inorder()
{
    Node* temp = this->root;

    inorder_helper(temp);
    cout << endl;
}

void Tree::postorder()
{
    Node* temp = this->root;

    postorder_helper(temp);
    cout << endl;
}

void Tree::levelorder()
{
    queue<Node*> bucket;

    bucket.push(this->root);

    while (!bucket.empty())
    {
        cout << bucket.front()->data << " ";

        if (bucket.front()->left != NULL)
            bucket.push(bucket.front()->left);
        
        if (bucket.front()->right != NULL)
            bucket.push(bucket.front()->right);
        
        bucket.pop();
    }
    cout << endl;
}

void Tree::preinpost()
{
    stack<pair<Node*, int>> bucket;
    vector<int> pre, in, post;
    pair<Node*, int> temp;

    temp.first = this->root;
    temp.second = 1;
    bucket.push(temp);

    while (!bucket.empty())
    {
        temp = bucket.top();
        bucket.pop();

        if (temp.second == 1)
        {
            pre.push_back(temp.first->data);
            temp.second = 2;
            bucket.push(temp);

            if (temp.first->left)
            {
                temp.first = temp.first->left;
                temp.second = 1;
                bucket.push(temp);
            }
        }

        else if (temp.second == 2)
        {
            in.push_back(temp.first->data);
            temp.second = 3;
            bucket.push(temp);

            if (temp.first->right)
            {
                temp.first = temp.first->right;
                temp.second = 1;
                bucket.push(temp);
            }
        }

        else 
        {
            post.push_back(temp.first->data);
        }
    }   

    cout << "Pre-Order: ";
    for (int i = 0; i < in.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout << endl; 

    cout << "In-Order: ";
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;  

    cout << "Post-Order: ";
    for (int i = 0; i < in.size(); i++)
    {
        cout << post[i] << " ";
    }
    cout << endl; 
}

int Tree::max_depth_helper(Node* ptroot)
{
    if (ptroot == NULL)
        return 0;
    
    int left_height = 1 + max_depth_helper(ptroot->left);
    int right_right = 1 + max_depth_helper(ptroot->right);

    return max(left_height, right_right);
}

int Tree::max_depth()
{
    Node* temp = this->root;

    return max_depth_helper(temp);
}

void Tree::zig_zag()
{
    deque<Node*> bucket;
    Node* temp;
    vector<int> res;
    int level = 1;

    bucket.push_back(this->root);
    res.push_back(this->root->data);

    while (!bucket.empty())
    {
        int n = bucket.size();

        for (int i = 0; i < n; i++)
        {
            if (level % 2 == 0)
            {
                temp = bucket.back();
                bucket.pop_back();

                if (temp->left)
                {
                    bucket.push_front(temp->left);
                    res.push_back(temp->left->data);
                }

                if (temp->right)
                {
                    bucket.push_front(temp->right);
                    res.push_back(temp->right->data);
                }
            }

            else 
            {
                temp = bucket.front();
                bucket.pop_front();

                if (temp->right)
                {
                    bucket.push_back(temp->right);
                    res.push_back(temp->right->data);
                }

                if (temp->left)
                {
                    bucket.push_back(temp->left);
                    res.push_back(temp->left->data);
                }
            }
        }
        level++;
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

Node* Tree::preInTree_helper(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &inorderIndex)
{
    if (inorderStart > inorderEnd)
        return NULL;

    Node* currNode = new Node(preorder[preorderIndex]);
    preorderIndex++;

    if (inorderStart == inorderEnd)
        return currNode;

    int curInorderIndex = inorderIndex[currNode->data];

    currNode->left = preInTree_helper(preorder, inorder, preorderIndex, inorderStart, curInorderIndex - 1, inorderIndex);

    currNode->right = preInTree_helper(preorder, inorder, preorderIndex, curInorderIndex + 1, inorderEnd, inorderIndex);

    return currNode;
}

void Tree::PreInTree(vector<int> preorder, vector<int> inorder)
{
    unordered_map<int, int> inorderIndex;
    int preorderIndex = 0;
    Node* temp;

    for (int i = 0; i < inorder.size(); i++)
    {
        inorderIndex[inorder[i]] = i;
    }

    temp = preInTree_helper(preorder, inorder, preorderIndex, 0, inorder.size() - 1, inorderIndex);

    this->root = temp;
}

void Tree::boundry_helper(Node* root, vector<int> &leaf)
{
    if (root == NULL)
        return;
    
    if (root->left == NULL && root->right == NULL)
        leaf.push_back(root->data);

    boundry_helper(root->left, leaf);
    boundry_helper(root->right, leaf);
}


void Tree::boundryPrint()
{
    Node* temp = this->root;
    vector<int> leaf;
    vector<int> left;
    stack<int> right;
    vector<int> res;

    boundry_helper(temp, leaf); // to store leaf nodes

    temp = root->left;

    while (temp != NULL)
    {
        left.push_back(temp->data);

        if (temp->left)
            temp = temp->left;
        else
            temp = temp->right;
        
        if (temp->left == NULL && temp->right == NULL)
            break;
    }

    temp = root->right;

    while (temp != NULL)
    {
        right.push(temp->data);
        
        if (temp->left)
            temp = temp->left;
        else
            temp = temp->right;
        
        if (temp->left == NULL && temp->right == NULL)
            break;
    }

    res.push_back(root->data);

    for (int i = 0; i < left.size(); i++)
    {
        res.push_back(left[i]);
    }

    for (int i = 0; i < leaf.size(); i++)
    {
        res.push_back(leaf[i]);
    }

    while (!right.empty())
    {
        res.push_back(right.top());
        right.pop();
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;
}

void Tree::vertical_traversal()
{
    queue<pair<Node*, pair<int, int>>> bucket; // to store root and the position (x, y)
    map<int, map<int, multiset<int>>> res; // to store answer at respective dimension
    vector<int> ans;

    bucket.push({this->root, {0, 0}});

    while (!bucket.empty())
    {
        auto temp = bucket.front();
        bucket.pop();

        int x = temp.second.first;
        int y = temp.second.second;

        res[x][y].insert(temp.first->data);

        if (temp.first->left)
            bucket.push({temp.first->left, {x - 1, y + 1}});
        
        if (temp.first->right)
            bucket.push({temp.first->right, {x + 1, y + 1}});
    }

    for (auto &pr : res)
    {
        for (auto &pr2 : pr.second)
        {
            ans.insert(ans.end(), pr2.second.begin(), pr2.second.end());
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*void Tree::top_view()
{
    queue<pair<Node*, pair<int, int>>> bucket;
    map<int, map<int, multiset<int>>> resmap;
    vector<int> res;

    bucket.push({this->root, {0, 0}});

    while (!bucket.empty())
    {
        auto temp = bucket.front();
        bucket.pop();

        int x = temp.second.first;
        int y = temp.second.second;

        if (abs(x) == abs(y)) // to store only top view elements
        {
            resmap[x][y].insert(temp.first->data);
        }

        if (temp.first->left)
            bucket.push({temp.first->left, {x - 1, y + 1}});

        if (temp.first->right)
            bucket.push({temp.first->right, {x + 1, y + 1}});
    }

    for (auto &pr : resmap)
    {
        for (auto &pr2 : pr.second)
        {
            res.insert(res.end(), pr2.second.begin(), pr2.second.end());
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}*/

void Tree::top_view()
{
    map<int, int> resmap; // to store Y axis and value
    queue<pair<Node*, int>> bucket; // to store Node* and Y axis
    vector<int> res; // to store answers

    bucket.push({this->root, 0});

    while (!bucket.empty())
    {
        auto temp = bucket.front();
        bucket.pop();

        if (resmap.find(temp.second) == resmap.end())
            resmap[temp.second] = temp.first->data;

        if (temp.first->left)
            bucket.push({temp.first->left, temp.second - 1});

        if (temp.first->right)
            bucket.push({temp.first->right, temp.second + 1});
    }

    for (auto itr = resmap.begin(); itr != resmap.end(); itr++)
    {
        res.push_back(itr->second);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;
}

void Tree::bottom_view()
{
    queue<pair<Node*, int>> bucket; //to store Node and Y axis
    map<int, int> resmap; // to store data while traversing
    vector<int> res;

    bucket.push({this->root, 0});

    while (!bucket.empty())
    {
        auto temp = bucket.front();
        bucket.pop();

        resmap[temp.second] = temp.first->data;

        if (temp.first->left)
            bucket.push({temp.first->left, temp.second - 1});

        if (temp.first->right)
            bucket.push({temp.first->right, temp.second + 1});
    }

    for (auto it = resmap.begin(); it != resmap.end(); it++)
    {
        res.push_back(it->second);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void Tree::right_view()
{
    queue<pair<Node*, int>> bucket;
    map<int, int> resmap;
    vector<int> res;

    bucket.push({this->root, 0});

    while (!bucket.empty())
    {
        auto temp = bucket.front();
        bucket.pop();

        if (resmap.find(temp.second) == resmap.end())
            resmap[temp.second] = temp.first->data;
        
        if (temp.first->right)
            bucket.push({temp.first->right, temp.second + 1});
        
        if (temp.first->left)
            bucket.push({temp.first->left, temp.second + 1});
    }

    for (auto it = resmap.begin(); it != resmap.end(); it++)
    {
        res.push_back(it->second);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void Tree::left_view()
{
    queue<pair<Node*, int>> bucket;
    map<int, int> resmap;
    vector<int> res;

    bucket.push({this->root, 0});

    while (!bucket.empty())
    {
        auto temp = bucket.front();
        bucket.pop();

        if (resmap.find(temp.second) == resmap.end())
            resmap[temp.second] = temp.first->data;
        
        if (temp.first->left)
            bucket.push({temp.first->left, temp.second + 1});
        
        if (temp.first->right)
            bucket.push({temp.first->right, temp.second + 1});
    }

    for (auto it = resmap.begin(); it != resmap.end(); it++)
    {
        res.push_back(it->second);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}


bool Tree::is_symmetrical_helper(Node* left, Node* right)
{
    if (left == NULL || right == NULL)
        return left == right;
    
    if (left->data != right->data)
        return false;
    
    return is_symmetrical_helper(left->left, right->right) && is_symmetrical_helper(left->right, right->left);
}


bool Tree::is_symmetrical()
{
    if (this->root == NULL)
        return true;
    
    return is_symmetrical_helper(root->left, root->right);
}


Heap::Heap()
{
    this->index = -1;
}

Heap::Heap(int size)
{
    this->index = -1;
    this->size = size;
    this->arr.resize(size);
}

void Heap::add_heap(int value)
{
    int child, parent;

    if (index == size - 1)
        return;
    
    this->arr[++index] = value;
    child = index;

    while (child != 0)
    {
        parent = (child - 1) / 2;

        if (arr[parent] < arr[child])
        {
            swap(arr[parent], arr[child]);
            child = parent;
        }
    }
}