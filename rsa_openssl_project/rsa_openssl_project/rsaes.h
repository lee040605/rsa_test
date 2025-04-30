#ifndef RSAENDE_H
#define RSAENDE_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool rsa_encrypt(const int8_t* plaintext, size_t length,
    uint8_t* encrypted, size_t* encrypted_len);

bool rsa_decrypt(const uint8_t* ciphertext, size_t length,
    int8_t* decrypted, size_t* decrypted_len);

#endif
