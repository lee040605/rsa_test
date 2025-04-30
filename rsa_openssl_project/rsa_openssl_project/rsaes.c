/*#include "rsaes.h"
#include <stdio.h>
#include <stdlib.h>

EVP_PKEY_CTX* EVP_PKEY_CTX_new_id(int id, void* e)
{
    EVP_PKEY_CTX* ctx = (EVP_PKEY_CTX*)malloc(sizeof(EVP_PKEY_CTX));
    if (!ctx)
        return NULL;

    ctx->key_id = id;
    ctx->key_bits = 0;
    ctx->pkey = NULL;
    return ctx;
}

void EVP_PKEY_CTX_free(EVP_PKEY_CTX* ctx)
{
    if (ctx)
        free(ctx);
}

int EVP_PKEY_keygen_init(EVP_PKEY_CTX* ctx)
{
    return (ctx != NULL);
}

int EVP_PKEY_CTX_set_rsa_keygen_bits(EVP_PKEY_CTX* ctx, int bits)
{
    if (!ctx || bits < 512)
        return 0;

    ctx->key_bits = bits;
    return 1;
}

int EVP_PKEY_keygen(EVP_PKEY_CTX* ctx, EVP_PKEY** ppkey)
{
    if (!ctx || !ppkey)
        return 0;

    *ppkey = (EVP_PKEY*)malloc(sizeof(EVP_PKEY));
    if (!*ppkey)
        return 0;

    (*ppkey)->key_id = ctx->key_id;
    (*ppkey)->key_bits = ctx->key_bits;
    return 1;
}

int PEM_write_PUBKEY(FILE* fp, EVP_PKEY* pkey)
{
    if (!fp || !pkey)
        return 0;

    fprintf(fp, "-----BEGIN PUBLIC KEY-----\n");
    fprintf(fp, "Simulated RSA Public Key (%d bits)\n", pkey->key_bits);
    fprintf(fp, "-----END PUBLIC KEY-----\n");
    return 1;
}

int PEM_write_PrivateKey(FILE* fp, EVP_PKEY* pkey, void* cipher, void* kstr, int klen, void* cb, void* u)
{
    if (!fp || !pkey)
        return 0;

    fprintf(fp, "-----BEGIN PRIVATE KEY-----\n");
    fprintf(fp, "Simulated RSA Private Key (%d bits)\n", pkey->key_bits);
    fprintf(fp, "-----END PRIVATE KEY-----\n");
    return 1;
}

void EVP_PKEY_free(EVP_PKEY* pkey)
{
    if (pkey)
        free(pkey);
}

int generate_rsa_key(const char* pub_filename, const char* priv_filename)
{
    printf("RSA 키 생성\n");

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(1, NULL);
    if (!ctx)
    {
        printf("EVP_PKEY_CTX 생성 실패\n");
        return 1;
    }

    if (EVP_PKEY_keygen_init(ctx) <= 0)
    {
        printf("EVP_PKEY_keygen_init 실패\n");
        EVP_PKEY_CTX_free(ctx);
        return 1;
    }

    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 2048) <= 0)
    {
        printf("키 길이 설정 실패\n");
        EVP_PKEY_CTX_free(ctx);
        return 1;
    }

    EVP_PKEY* pkey = NULL;
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0)
    {
        printf("키 생성 실패\n");
        EVP_PKEY_CTX_free(ctx);
        return 1;
    }

    FILE* fp_pub = fopen(pub_filename, "wb");
    if (!fp_pub || PEM_write_PUBKEY(fp_pub, pkey) == 0)
    {
        printf("공개키 저장 실패\n");
        if (fp_pub) fclose(fp_pub);
        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(ctx);
        return 1;
    }
    fclose(fp_pub);

    FILE* fp_priv = fopen(priv_filename, "wb");
    if (!fp_priv || PEM_write_PrivateKey(fp_priv, pkey, NULL, NULL, 0, NULL, NULL) == 0)
    {
        printf("개인키 저장 실패\n");
        if (fp_priv) fclose(fp_priv);
        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(ctx);
        return 1;
    }
    fclose(fp_priv);

    printf("RSA 키 생성 완료\n");

    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(ctx);

    return 0;
}
*/