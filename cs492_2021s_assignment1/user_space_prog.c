#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYS_shilong 332

int main(int argc, char **argv)
{
    // constuct string a which exceeds 128 length
    int a_len = 200;
    char* a = (char*)malloc(a_len+1);
    for (int i = 0; i < a_len; ++i)
    {
        a[i] = 'a';
    }
    a[a_len] = '\0';

    // call syscall with a
    printf("Making system call with \"%s\"(len = 200)\n", a);
    int res = syscall(SYS_shilong, a);
    printf("System call returned %d\n", res);

    // construct valid string b which has 6 'x'
    const char* normal_str = "x90x009wx99xx2xlll";
    int b_len = strlen(normal_str);
    char* b = (char*)malloc(b_len+1);
    for (int i = 0; i < b_len; ++i)
    {
        b[i] = normal_str[i];
    }
    b[b_len] = '\0';

    // call syscall with b
    printf("Making system call with \"%s\"(with 6 'x')\n", b);
    res = syscall(SYS_shilong, b);
    printf("System call returned %d\n", res);
    printf("The modified string b is: \"%s\" now\n", b);
}