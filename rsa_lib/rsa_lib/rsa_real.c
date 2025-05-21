#include "rsa_real.h"
#include "rsa_math.h"
#include <string.h>
#include <stdio.h>

// Dummy 64-bit test key (RSA: p=61, q=53 → n=3233, e=17, d=2753)
#define PUBLIC_EXPONENT 17
#define PRIVATE_EXPONENT 2753
#define MODULUS 3233

int rsa_encrypt_real(const char* input, uint64_t* encrypted, size_t* len)
{
    size_t msg_len = strlen(input);
    *len = msg_len;

    for (size_t i = 0; i < msg_len; ++i)
    {
        uint64_t m = (uint64_t)input[i];
        encrypted[i] = modexp(m, PUBLIC_EXPONENT, MODULUS);
        printf("[Encryption][%c] result = 0x%llx\n", input[i], encrypted[i]);
    }

    return 1;
}

int rsa_decrypt_real(const uint64_t* encrypted, size_t len, char* output)
{
    for (size_t i = 0; i < len; ++i)
    {
        uint64_t dec = modexp(encrypted[i], PRIVATE_EXPONENT, MODULUS);
        output[i] = (char)dec;
        printf("[Decryption][%zu] result = 0x%llx ⇒ output[%zu] = %c\n", i, dec, i, output[i]);
    }

    output[len] = '\0';
    return 1;
}
