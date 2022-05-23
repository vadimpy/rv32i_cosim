int a[10] = {2, 4, 1, 2, 3, 5, 0, 7, 0, 6};

void inline_ecall() {
    asm volatile ("ecall");
}

int _start() {
    for (int i = 0; i < 9; ++i)
        for (int j = i; j < 10; ++j)
            if (a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
}
