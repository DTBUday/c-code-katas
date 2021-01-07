/**
 * Sieve of eratosthenes.
 * 
 * https://projecteuler.net/problem=7
 * https://projecteuler.net/problem=10
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

bool is_prime(int number)
{
    int root = (int) sqrt(number);

    for (int i = 2; i <= root; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int *sieve_of_eratosthenes(int n)
{
    int root, *primes;

    primes = (int *) malloc(n * sizeof(int));

    primes[0] = primes[1] = 0;
    for (int i = 2; i < n; i++) {
        primes[i] = 1;
    }

    root = (int) sqrt(n);

    for (int i = 2; i <= root; i++) {
        if (is_prime(i)) {
            for (int j = 2; (i * j) <= n; j++) {
                primes[i * j] = 0;
            }
        }
    }

    return primes;
}

int main()
{
    int n = 10000, *primes;

    printf("%s%d\n", "How many data? ", n);

    primes = sieve_of_eratosthenes(n);

    for (int i = 0; i < n; i++) {
        if (primes[i]) {
            printf("%d ", i);
            assert(is_prime(i));
        }
    }

    return 0;
}
