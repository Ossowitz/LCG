/**
 * @author:  https://github.com/Ossowitz
 * @author:  https://t.me/DispatcherServlet
 * @version: 1.0
 * TODO: implementation LKG
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define STATELESS                   "\033[1;32m%s\033[0m\n"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define NO_SOLUTION_EXCEPTION       "no solution"
#define FILE_OPENED                 "+ FILE OPENED +"
#define OUTPUT_FILE                 "output.txt"

/**
 * @param:  n - numeric
 * @return: Checking whether a number is prime
 * @see:    https://habr.com/ru/articles/205318/
 */
bool isPrime(unsigned long long n) {
    if (n > 1) {
        for (unsigned long long i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

/**
 * @param: m - numeric
 * @brief: Find the minimum a such that a-1 is divisible by all prime divisors of m.\note
 *          If m is divisible by 4 then a-1 is divisible by 4;
 */
void get_a(unsigned long long m) {
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
    for (unsigned long long j = 3; j < sqrt(m); j += 2) {
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
                "a = %lld", a + 1
        );
    }
}