#include <stdio.h>

#include "crc16.h"
#include "crc64.h"
#include "sha1.h"

#define BUFSIZE 4096

int main(int argc, char** argv)
{
    printf("crc64 %016llx\n", (unsigned long long) crc64(0,(unsigned char*)"123456789",9));
    printf("crc16 %04x\n", (unsigned short) crc16((unsigned char*)"123456789",9));

    SHA1_CTX ctx;
    unsigned char hash[20], buf[BUFSIZE];
    int i;

    for(i=0;i<BUFSIZE;i++)
        buf[i] = i;

    SHA1Init(&ctx);
    for(i=0;i<1000;i++)
        SHA1Update(&ctx, buf, BUFSIZE);
    SHA1Final(hash, &ctx);

    printf("SHA1=");
    for(i=0;i<20;i++)
        printf("%02x", hash[i]);
    printf("\n");

    return 0;
}
