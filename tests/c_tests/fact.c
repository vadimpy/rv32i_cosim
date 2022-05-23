void inline_ecall() {
    asm volatile ("ecall");
}

int my_mul(int a, int b) {
    int s = 0;
    for (int i = 0; i < b; ++i)
        s += a;
    return s;
}

int fact(int n) {
    if (n == 0)
        return 1;
    return my_mul(n, fact(n - 1));
}

void _start() {
    int fact_9 = fact(9);
}
