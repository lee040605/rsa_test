#ifndef RSA_PADDING_H
#define RSA_PADDING_H

#include <stdint.h>
#include <stddef.h>

int pkcs1_v15_pad(const uint8_t* msg, size_t msg_len, uint8_t* block, size_t k);
int pkcs1_v15_unpad(const uint8_t* block, size_t k, uint8_t* msg, size_t* msg_len);

#endif
