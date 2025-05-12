#ifndef RSAES_H
#define RSAES_H

#include <stdint.h>
#include <stddef.h>

int rsa_encrypt_real(const char* input, uint64_t* encrypted, size_t* len);
int rsa_decrypt_real(const uint64_t* encrypted, size_t len, char* output);

#endif
