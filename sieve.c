#include <stdlib.h>
int* sieve(int n, int *count) {
    if (n < 2) {
        *count = 0;
        return NULL;
    }

    char* is_prime = calloc(n + 1, sizeof(char));
    for (int i = 2; i <= n; i++) {
        is_prime[i] = 1;
    }

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    *count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) (*count)++;
    }

    int* prime = malloc(*count * sizeof(int));
    if (!prime) {
        free(is_prime);
        *count = 0;
        return NULL;
    }

    int index = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) prime[index++] = i;
    }

    free(is_prime);
    return primes;
}