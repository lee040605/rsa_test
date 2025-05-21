#include "rsa_real.h"
#include "rsa_encrypt.h"
#include "rsa_padding.h"
#include "rsa_math_big.h"
#include <string.h>
#include <stdio.h>

int rsa_encrypt_real(const char* input, uint8_t output[][128], size_t* len, int padding_type)
{
    size_t msg_len = strlen(input);
    *len = msg_len;

    for (size_t i = 0; i < msg_len; ++i)
    {
        uint8_t padded[128] = { 0 };
        uint8_t result[128] = { 0 };

        if (padding_type == 1)
        {
            if (!pkcs1_v15_pad((uint8_t*)&input[i], 1, padded, 128))
            {
                printf("Padding failed\n");
                return 0;
            }
        }
        else
        {
            memset(padded, 0, 128);
            padded[127] = (uint8_t)input[i];
        }

        if (!modexp_big(padded, 128,
            PUBLIC_EXPONENT, sizeof(PUBLIC_EXPONENT),
            MODULUS, sizeof(MODULUS),
            result, 128))
        {
            printf("modexp_big failed\n");
            return 0;
        }

        memcpy(output[i], result, 128);
    }

    return 1;
}

int rsa_decrypt_real(const uint8_t input[][128], size_t len, char* output, int padding_type)
{
    for (size_t i = 0; i < len; ++i)
    {
        uint8_t decrypted[128] = { 0 };

        if (!modexp_big(input[i], 128,
            PRIVATE_EXPONENT, sizeof(PRIVATE_EXPONENT),
            MODULUS, sizeof(MODULUS),
            decrypted, 128))
        {
            printf("modexp_big (decrypt) failed\n");
            return 0;
        }

        if (padding_type == 1)
        {
            size_t outlen = 0;
            if (!pkcs1_v15_unpad(decrypted, 128, (uint8_t*)&output[i], &outlen) || outlen != 1)
            {
                printf("Unpadding failed\n");
                return 0;
            }
        }
        else
        {
            output[i] = (char)decrypted[127];
        }
    }

    output[len] = '\0';
    return 1;
}
