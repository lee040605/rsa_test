#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#include "rsaes.h"        // rsa_encrypt, rsa_decrypt 선언
#include "rsa_encrypt.h"  // pub_key_der 사용

int main(void)
{
    // 한글 입출력 설정 (선택사항)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "");

    int8_t message[256] = { 0 };
    uint8_t encrypted[256] = { 0 };
    int8_t decrypted[256] = { 0 };
    size_t encrypted_len = 0, decrypted_len = 0;

    // 입력
    printf("Please enter: ");
    fgets((char*)message, sizeof(message), stdin);
    message[strcspn((char*)message, "\r\n")] = '\0';  // 개행 제거

    printf("[Original text] %s\n", message);

    // 암호화
    if (!rsa_encrypt(message, strlen((char*)message) + 1, encrypted, &encrypted_len))
    {
        printf("암호화 실패!\n");
        return 1;
    }

    printf("[Cryptogram text] ");
    for (size_t i = 0; i < encrypted_len; i++)
    {
        printf("%02X ", encrypted[i]);
    }
    printf("\n");

    // 복호화
    if (!rsa_decrypt(encrypted, encrypted_len, decrypted, &decrypted_len))
    {
        printf("복호화 실패!\n");
        return 1;
    }

    printf("[Decryption text] %s\n", decrypted);

    // 콘솔 꺼짐 방지
    printf("\end\n");
    getchar();

    return 0;
}
