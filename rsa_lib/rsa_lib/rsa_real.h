#ifndef RSA_REAL_H
#define RSA_REAL_H

#include <stdint.h>
#include <stddef.h>

int rsa_encrypt_real(const char* input, uint8_t output[][128], size_t* len);
int rsa_decrypt_real(const uint8_t input[][128], size_t len, char* output);

#endif
