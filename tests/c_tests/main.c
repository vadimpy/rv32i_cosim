#include "stdint.h"
#include "stdio.h"

uint32_t a[10] = {2, 4, 1, 2, 3, 5, 0, 7, 0, 6};

int main() {
    for (int i = 0; i < 9; ++i)
        for (int j = i; j < 10; ++j)
            if (a[i] > a[j]) {
                unsigned int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    for (int i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
