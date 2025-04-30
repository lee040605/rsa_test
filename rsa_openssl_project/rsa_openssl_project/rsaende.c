#include <stdint.h>     
#include <stdbool.h> 
#include <string.h>

#include "rsaende.h"
#include "rsa_encrypt.h"


// 빅엔디안 변환 (4바이트 단위)
static void to_big_endian(uint8_t* data, size_t length)
{
    for (size_t i = 0; i + 3 < length; i += 4)
    {
        uint8_t tmp0 = data[i];
        uint8_t tmp1 = data[i + 1];
        data[i] = data[i + 3];
        data[i + 1] = data[i + 2];
        data[i + 2] = tmp1;
        data[i + 3] = tmp0;
    }
}

bool rsa_encrypt(const int8_t* plaintext, size_t length,
    uint8_t* encrypted, size_t* encrypted_len)
{
    if (length > sizeof(pub_key_der)) return false;

    for (size_t i = 0; i < length; i++)
    {
        encrypted[i] = (uint8_t)plaintext[i] ^ pub_key_der[i % sizeof(pub_key_der)];
    }

    to_big_endian(encrypted, length);
    *encrypted_len = length;
    return true;
}

bool rsa_decrypt(const uint8_t* ciphertext, size_t length,
    int8_t* decrypted, size_t* decrypted_len)
{
    if (length > sizeof(pub_key_der)) return false;

    uint8_t temp[512];
    memcpy(temp, ciphertext, length);
    to_big_endian(temp, length);

    for (size_t i = 0; i < length; i++)
    {
        decrypted[i] = (int8_t)(temp[i] ^ pub_key_der[i % sizeof(pub_key_der)]);
    }

    *decrypted_len = length;
    return true;
}
