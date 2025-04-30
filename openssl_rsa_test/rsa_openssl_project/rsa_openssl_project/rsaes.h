#ifndef RSAES_H
#define RSAES_H

#include <stdio.h>  // FILE 타입 사용하려면 필요함

typedef struct
{
    int key_id;
    int key_bits;
    void* pkey; // 실제 구현에선 더 복잡한 구조를 쓸 수 있음
} EVP_PKEY;

typedef struct
{
    int key_id;
    int key_bits;
    EVP_PKEY* pkey;
} EVP_PKEY_CTX;

EVP_PKEY_CTX* EVP_PKEY_CTX_new_id(int id, void* e);
void EVP_PKEY_CTX_free(EVP_PKEY_CTX* ctx);
int EVP_PKEY_keygen_init(EVP_PKEY_CTX* ctx);
int EVP_PKEY_CTX_set_rsa_keygen_bits(EVP_PKEY_CTX* ctx, int bits);
int EVP_PKEY_keygen(EVP_PKEY_CTX* ctx, EVP_PKEY** ppkey);
int PEM_write_PUBKEY(FILE* fp, EVP_PKEY* pkey);
int PEM_write_PrivateKey(FILE* fp, EVP_PKEY* pkey, void* cipher, void* kstr, int klen, void* cb, void* u);

int generate_rsa_key(const char* pub_filename, const char* priv_filename);

#endif // RSAES_H
