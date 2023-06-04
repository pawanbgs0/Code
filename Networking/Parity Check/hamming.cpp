#include <bits/stdc++.h>
using namespace std;

// function to generate Hamming code
vector<int> generateHammingCode(vector<int> data) 
{
    int n = data.size();
    int k = n - 1;
    int r = 1;
    while (r < n) 
    {
        r *= 2;
    }
    vector<int> parityBits(r - n);
    for (int i = 0; i < r - n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if ((i & (1 << j)) != 0) 
            {
                parityBits[i] ^= data[j];
            }
        }
    }
    data.insert(data.end(), parityBits.begin(), parityBits.end());
    return data;
}

// function to check Hamming code
bool checkHammingCode(vector<int> data) 
{
    int n = data.size();
    int k = n - 1;
    int r = 1;
    while (r < n) 
    {
        r *= 2;
    }
    vector<int> parityBits(r - n);
    for (int i = 0; i < r - n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if ((i & (1 << j)) != 0) 
            {
                parityBits[i] ^= data[j];
            }
        }
    }
    for (int i = 0; i < r - n; i++) 
    {
        if (parityBits[i] != 0) 
        {
            // error detected
            int errorPosition = (r - 1) - i;
            data[errorPosition] ^= 1;
        }
    }
    return true;
}

// function to fix error
void fixError(vector<int> data) 
{
    int n = data.size();
    int k = n - 1;
    int r = 1;
    while (r < n) 
    {
        r *= 2;
    }
    vector<int> parityBits(r - n);
    for (int i = 0; i < r - n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if ((i & (1 << j)) != 0) 
            {
                parityBits[i] ^= data[j];
            }
        }
    }
    for (int i = 0; i < r - n; i++) 
    {
        if (parityBits[i] != 0) 
        {
            // error detected
            int errorPosition = (r - 1) - i;
            data[errorPosition] ^= 1;
            break;
        }
    }
}

// example usage
int main() {
    vector<int> data = {0, 1, 0, 1};
    
    // generate Hamming code
    vector<int> hammingCode = generateHammingCode(data);
    
    // check Hamming code
    if (checkHammingCode(hammingCode)) 
    {
        cout << "No error detected" << endl;
    } else 
    {
        cout << "Error detected" << endl;
        fixError(hammingCode);
        cout << "Error fixed" << endl;
    }
    
    return 0;
}