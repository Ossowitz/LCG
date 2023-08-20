#include <stdio.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define STATELESS                   "\033[1;32m%s\033[0m\n"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define NO_SOLUTION_EXCEPTION       "no solution"
#define FILE_OPENED                 "+ FILE OPENED +"
#define OUTPUT_FILE                 "output.txt"

long long areCoprime(long long a, long long b) {
    if (b == 0) {
        return a == 1;
    }

    return areCoprime(b, a % b);
}

void get_c(long long cmin, long long cmax, long long m) {
    FILE *file = fopen(OUTPUT_FILE, "w");
    if (file != NULL) {
        for (long long c = cmin; c <= cmax; c++) {
            if (c > 0 && c < m && areCoprime(c, m)) {
                fprintf(file, "%d\n", c);
                printf("%d\n", c);
            }
        }
        fclose(file);
    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
    }
}