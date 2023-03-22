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

Huffman::Huffman(string input_file_name)
{
    this->TreeRoot = NULL;
    this->input = input_file_name;
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


void Huffman::take_input(string input_file_name)
{
    fstream f;
    char temp;

    ifstream src(input_file_name); // checking if string is valid;
    

    if (src)
    {
        f.open(input_file_name.c_str(), ios::in);
        while (src.good())
        {
            src.get(temp);
            this->input += temp;
        } // this is taking last char twice
    }
    else 
        cout << "File does not exist." << endl;
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


//...................................Binary Tree .....................................................
Binary_Tree::Binary_Tree()
{
    this->root = NULL;
    this->level = 0;
}

void Binary_Tree::takeInput(vector<string> input)
{
    // int size;

    // cout << "Enter the size of input: ";
    // cin >> size;

    // for (int i = 0; i < size; i++)
    // {
    //     string temp;
    //     cout << "Enter the input string " << i + 1 << ": ";
    //     cin >> temp;

    //     level = max(level, (int)temp.size());
    //     input.push_back(temp);
    // }

    this->input = input;

    for(auto &it: input)
    {
        level = max(level, (int)it.size());
        cout << it << endl;
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
        // cout << endl;
    }
    // levelOrder();
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

vector<unsigned char> EndEncryption::aes_encrypt()
{
    vector<unsigned char> encrypted_data(data.size() + EVP_MAX_BLOCK_LENGTH);
    int encrypted_length = 0;

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, &key[0], NULL);
    EVP_EncryptUpdate(ctx, &encrypted_data[0], &encrypted_length, &data[0], data.size());
    int final_length = 0;
    EVP_EncryptFinal_ex(ctx, &encrypted_data[encrypted_length], &final_length);
    encrypted_length += final_length;
    EVP_CIPHER_CTX_free(ctx);

    encrypted_data.resize(encrypted_length);
    return encrypted_data;
}

vector<unsigned char> EndEncryption::aes_decrypt()
{
    vector<unsigned char> decrypted_data(data.size() + EVP_MAX_BLOCK_LENGTH);
    int decrypted_length = 0;

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, &key[0], NULL);
    EVP_DecryptUpdate(ctx, &decrypted_data[0], &decrypted_length, &data[0], data.size());
    int final_length = 0;
    EVP_DecryptFinal_ex(ctx, &decrypted_data[decrypted_length], &final_length);
    decrypted_length += final_length;
    EVP_CIPHER_CTX_free(ctx);

    decrypted_data.resize(decrypted_length);
    return decrypted_data;
}