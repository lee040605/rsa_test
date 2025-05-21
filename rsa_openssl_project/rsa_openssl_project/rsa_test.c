#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "rsa_real.h"

int main()
{
    const char* message = "i love dokdo";
    uint8_t encrypted[256][128] = { 0 };
    char decrypted[256] = { 0 };
    size_t len = 0;
    int padding_type = 0;

    printf("Padding Type :\n");
    printf("1: PKCS#1 v1.5\n");
    printf("2: No Padding\n: ");
    scanf("%d", &padding_type);

    printf("Original message: %s\n\n", message);
    printf("[Encryption]\n");
    rsa_encrypt_real(message, encrypted, &len, padding_type);

    for (size_t i = 0; i < len; ++i)
    {
        printf("[%c] -> [0x", message[i]);
        for (int j = 0; j < 128; ++j)
        {
            printf("%02X", encrypted[i][j]);
        }
        printf("]\n");
    }

    printf("\n[Decryption]\n");
    rsa_decrypt_real(encrypted, len, decrypted, padding_type);

    for (size_t i = 0; i < len; ++i)
    {
        printf("[0x");
        for (int j = 0; j < 128; ++j)
        {
            printf("%02X", encrypted[i][j]);
        }
        printf("] -> [%c]\n", decrypted[i]);
    }

    printf("\nDecrypted message: %s\n", decrypted);
    return 0;
}
