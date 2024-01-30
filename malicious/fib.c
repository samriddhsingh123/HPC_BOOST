#include <stdio.h>

long long fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    printf("fib(35) = %lld\n", fib(35));
    return 0;
}
