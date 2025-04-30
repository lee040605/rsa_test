#include <stdio.h>
#include <string.h>
#include "rsa_encrypt.h"

int rsa_encrypt_data(const unsigned char* plaintext, size_t plaintext_len,
    unsigned char* encrypted, size_t* encrypted_len)
{
    if (plaintext_len > sizeof(pub_key_der))
        return 0;

    for (size_t i = 0; i < plaintext_len; i++)
    {
        encrypted[i] = plaintext[i] ^ pub_key_der[i % sizeof(pub_key_der)];
    }
    *encrypted_len = plaintext_len;
    return 1;
}

int rsa_decrypt_data(const unsigned char* ciphertext, size_t ciphertext_len,
    unsigned char* decrypted, size_t* decrypted_len)
{
    if (ciphertext_len > sizeof(priv_key_der))
        return 0;

    for (size_t i = 0; i < ciphertext_len; i++)
    {
        decrypted[i] = ciphertext[i] ^ priv_key_der[i % sizeof(priv_key_der)];
    }
    *decrypted_len = ciphertext_len;
    return 1;
}
