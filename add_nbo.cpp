#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
    FILE* fb1 = NULL;
    FILE* fb2 = NULL;

    uint32_t  n1 = 0;
    uint32_t  n2 = 0;
    uint32_t  n3 = 0;
    uint32_t  n4 = 0;

    fb1 = fopen(argv[1], "rb");
    fb2 = fopen(argv[2], "rb");

    fread(&n1, sizeof(n1), 1, fb1);
    fread(&n2, sizeof(n2), 1, fb2);

    n3 = ntohl(n1);
    n4 = ntohl(n2);

    printf("%d(0x%02x) + %d(0x%02x) = %d(0x%02x)\n", n3, n3, n4, n4, n3 + n4, n3 + n4);

    fclose(fb1);
    fclose(fb2);

    return 0;
}