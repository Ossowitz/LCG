#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define STATELESS                   "\033[1;32m%s\033[0m\n"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define NO_SOLUTION_EXCEPTION       "no solution"
#define FILE_OPENED                 "+ FILE OPENED +"
#define OUTPUT_FILE                 "output.txt"

bool isPrime(long long n) {
    if (n > 1) {
        for (long long i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

void get_a(long long m) {
    FILE *output = fopen(OUTPUT_FILE, "w");
    long long a = 0;
    if (output == NULL) {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }
    if (m % 2 == 0) {
        a = 2;
    }
    if (m % 4 == 0) {
        a = 4;
    }
    for (int j = 3; j < sqrt(m); j += 2) {
        if ((m % j == 0) && (isPrime(j) == true)) {
            a *= j;
        }
    }
    if (a == 0 || a > m) {
        fprintf(output,
                NO_SOLUTION_EXCEPTION
        );
    } else {
        fprintf(output,
                "a = %lld", a + 1);
    }
}