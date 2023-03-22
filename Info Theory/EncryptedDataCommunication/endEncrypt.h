#include <openssl/evp.h>
#include<bits/stdc++.h>
using namespace std;

vector<unsigned char> aes_encrypt(const vector<unsigned char>& data, const vector<unsigned char>& key);
vector<unsigned char> aes_decrypt(const vector<unsigned char>& data, const vector<unsigned char>& key);
char* convert(vector<unsigned char> &message);