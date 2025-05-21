#include "rsa_math_big.h"
#include <string.h>

// Big number modular exponentiation (square and multiply)
int modexp_big(const uint8_t* base, size_t base_len,
    const uint8_t* exp, size_t exp_len,
    const uint8_t* mod, size_t mod_len,
    uint8_t* result, size_t result_len)
{
    uint8_t temp[256] = { 0 };
    uint8_t acc[256] = { 0 };
    acc[result_len - 1] = 1; // acc = 1

    memcpy(temp + (result_len - base_len), base, base_len);

    for (size_t i = 0; i < exp_len; ++i)
    {
        uint8_t byte = exp[i];
        for (int bit = 7; bit >= 0; --bit)
        {
            // acc = acc^2 mod mod
            // (dummy: ignore real mod operation for simplicity)
            // acc *= acc

            // if exp bit == 1, acc *= temp
            if ((byte >> bit) & 1)
            {
                // (dummy: acc *= base) — simulation
                memcpy(acc, temp, result_len);
            }
        }
    }

    memcpy(result, acc, result_len);
    return 1;
}
