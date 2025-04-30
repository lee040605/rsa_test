#ifndef RSAENDE_H
#define RSAENDE_H

#include <stddef.h>  // size_t


int rsa_encrypt_data(const unsigned char* plaintext, size_t plaintext_len,
    unsigned char* encrypted, size_t* encrypted_len);


int rsa_decrypt_data(const unsigned char* ciphertext, size_t ciphertext_len,
    unsigned char* decrypted, size_t* decrypted_len);

#endif
