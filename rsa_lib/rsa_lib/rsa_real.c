#include "rsa_real.h"
#include "rsa_math.h"
#include "rsa_encrypt.h"
#include <string.h>
#include <stdio.h>

// 간단히 N과 e, d 값을 추출 (2048비트 키라고 가정)
#define PUBLIC_EXPONENT 65537
#define MODULUS 0x00C244BCCF5BCACD // 키에서 추출한 일부 (실제 프로젝트에서는 키를 파싱해야 함)
#define PRIVATE_EXPONENT 0x225DB98EEF1C91BD // 마찬가지로 키에서 추출한 일부

int rsa_encrypt_real(const char* input, uint64_t* encrypted, size_t* len)
{
    size_t msg_len = strlen(input);
    *len = msg_len;

    for (size_t i = 0; i < msg_len; ++i)
    {
        encrypted[i] = modexp((uint64_t)input[i], PUBLIC_EXPONENT, MODULUS);
    }
    return 1;
}

int rsa_decrypt_real(const uint64_t* encrypted, size_t len, char* output)
{
    for (size_t i = 0; i < len; ++i)
    {
        output[i] = (char)modexp(encrypted[i], PRIVATE_EXPONENT, MODULUS);
    }
    output[len] = '\0';
    return 1;
}
