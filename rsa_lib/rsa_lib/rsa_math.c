#include "rsa_math.h"

uint64_t modexp(uint64_t base, uint64_t exp, uint64_t mod)
{
    uint64_t result = 1;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}
