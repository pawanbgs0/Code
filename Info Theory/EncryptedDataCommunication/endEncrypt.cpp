#include "endEncrypt.h"

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

char* convert(vector<unsigned char> &message)
{
    char* res = reinterpret_cast<char*>(message.data());

    return res;
}