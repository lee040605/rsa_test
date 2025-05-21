#include "rsa_padding.h"
#include <string.h>
#include <stdlib.h>

int pkcs1_v15_pad(const uint8_t* msg, size_t msg_len, uint8_t* block, size_t k)
{
    if (msg_len > k - 11)  // 최소 11바이트는 패딩에 필요
        return 0;

    block[0] = 0x00;
    block[1] = 0x02;

    size_t ps_len = k - msg_len - 3;
    for (size_t i = 0; i < ps_len; ++i)
    {
        uint8_t r = 0;
        while (r == 0)
            r = (uint8_t)(rand() % 256);
        block[2 + i] = r;
    }

    block[2 + ps_len] = 0x00;
    memcpy(block + 3 + ps_len, msg, msg_len);
    return 1;
}

int pkcs1_v15_unpad(const uint8_t* block, size_t k, uint8_t* msg, size_t* msg_len)
{
    if (k < 11 || block[0] != 0x00 || block[1] != 0x02)
        return 0;

    size_t i = 2;
    while (i < k && block[i] != 0x00)
        ++i;

    if (i >= k || i < 10)
        return 0;

    *msg_len = k - i - 1;
    memcpy(msg, block + i + 1, *msg_len);
    return 1;
}
