#include <stdint.h>
#include <stdio.h>

int main(void) {
    printf("%lu %lu", sizeof(int) * 8, sizeof(long int) * 8);
}