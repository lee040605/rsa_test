#ifndef RSA_MATH_H
#define RSA_MATH_H

#include <stdint.h>
#include <stddef.h>

uint64_t modexp(uint64_t base, uint64_t exp, uint64_t mod);
int modinv(int a, int m);

#endif
