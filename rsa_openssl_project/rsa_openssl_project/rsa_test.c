#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "rsa_real.h"

int main()
{
    const char* message = "i love dokdo";
    uint64_t encrypted[256] = { 0 };
    char decrypted[256] = { 0 };
    size_t len = 0;

    printf("Original message: %s\n\n", message);
    printf("[Encryption]\n");
    rsa_encrypt_real(message, encrypted, &len);

    for (size_t i = 0; i < len; ++i)
        printf("[%c] -> [0x%llx]\n", message[i], encrypted[i]);

    printf("\n[Decryption]\n");
    rsa_decrypt_real(encrypted, len, decrypted);

    for (size_t i = 0; i < len; ++i)
        printf("[0x%llx] -> [%c]\n", encrypted[i], decrypted[i]);

    printf("\nDecrypted message: %s\n", decrypted);
    return 0;
}
