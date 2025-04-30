#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "rsaes.h"
#include "rsa_encrypt.h"

// rsaende.c 에 선언된 암복호화 함수
int rsa_encrypt_data(const unsigned char* plaintext, size_t plaintext_len,
    unsigned char* encrypted, size_t* encrypted_len);

int rsa_decrypt_data(const unsigned char* ciphertext, size_t ciphertext_len,
    unsigned char* decrypted, size_t* decrypted_len);

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    const char* message = "Hello, RSA!";
    unsigned char encrypted[256] = { 0 };
    unsigned char decrypted[256] = { 0 };
    size_t encrypted_len = 0;
    size_t decrypted_len = 0;

    printf("원문: %s\n", message);

    if (!rsa_encrypt_data((const unsigned char*)message, strlen(message), encrypted, &encrypted_len))
    {
        printf("암호화 실패\n");
        return 1;
    }

    printf("암호문 (HEX): ");
    for (size_t i = 0; i < encrypted_len; i++)
    {
        printf("%02X", encrypted[i]);
    }
    printf("\n");

    if (!rsa_decrypt_data(encrypted, encrypted_len, decrypted, &decrypted_len))
    {
        printf("복호화 실패\n");
        return 1;
    }

    decrypted[decrypted_len] = '\0'; // 문자열 종료 처리
    printf("복호문: %s\n", decrypted);

    return 0;
}
