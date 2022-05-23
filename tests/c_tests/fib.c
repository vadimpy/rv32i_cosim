#define N 10
int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void inline_ecall() {
    asm volatile ("ecall");
}

void _start() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < N; ++i)
        a[i] = a[i - 1] + a[i - 2];
    int x = a[N-1];
}
