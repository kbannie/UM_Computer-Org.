#include <stdio.h>

union FU{
    float f;
    unsigned int u;
};

void binary(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    union FU num;

    printf("Please enter a number ");
    scanf("%f", &num.f);

    unsigned int sign = (num.u >> 31) & 1;

    unsigned int exp = (num.u >> 23) & 0xFF;

    unsigned int frac = num.u & 0x7FFFFF;

    printf("sign: %d\n", sign);
    printf("exp: ");
    binary(exp, 8); 
    printf("\nfrac: ");
    binary(frac, 23);
    printf("\n");

    return 0;
}