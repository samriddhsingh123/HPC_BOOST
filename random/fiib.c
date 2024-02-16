#include <stdio.h>

long long fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    printf("fib(50) = %lld\n", fib(44));
    return 0;
}
