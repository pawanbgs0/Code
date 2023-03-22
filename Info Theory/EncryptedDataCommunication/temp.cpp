#include <openssl/evp.h>
#include<bits/stdc++.h>
using namespace std;

vector<unsigned char> aes_encrypt(const vector<unsigned char>& data, const vector<unsigned char>& key)
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

vector<unsigned char> aes_decrypt(const vector<unsigned char>& data, const vector<unsigned char>& key)
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


int main() {
    // Huffman-encoded string
    string huffman_str = "0111010001100101011100110111010001101111011100100110110001100100001000000110010001101111011011100110010100100000011011010110010101100011011010000110100101101110011001110010000001101100011010010111001001100101001000000110001001100101001000000111010001101000011011110110111000101110";

    // Convert the string to a vector of bytes
    vector<unsigned char> huffman_data(huffman_str.begin(), huffman_str.end());

    // Encryption key
    vector<unsigned char> key = {'s', 'e', 'c', 'r', 'e', 't', 'k', 'e', 'y'};

    // Encrypt the Huffman data using AES
    vector<unsigned char> encrypted_data = aes_encrypt(huffman_data, key);

    // Decrypt the encrypted data using AES
    vector<unsigned char> decrypted_data = aes_decrypt(encrypted_data, key);

    // Convert the decrypted data to a string
    string decrypted_str(decrypted_data.begin(), decrypted_data.end());

    // Print the original and decrypted strings
    cout << "Original string: " << huffman_str << endl;
    cout << "Decrypted string: " << decrypted_str << endl;

    return 0;
}
