#ifndef RSA_MATH_BIG_H
#define RSA_MATH_BIG_H

#include <stdint.h>
#include <stddef.h>

int modexp_big(const uint8_t* base, size_t base_len,
    const uint8_t* exp, size_t exp_len,
    const uint8_t* mod, size_t mod_len,
    uint8_t* result, size_t result_len);

#endif
