#include <stdio.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define OUTPUT_FILE                 "output.txt"

void lcg(long long a, long long x0, long long c, long long m, long long n) {
    FILE *output = fopen(OUTPUT_FILE, "w");
    long long xn = x0;

    if (output == NULL) {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }

    for (int i = 0; i < n; i++) {
        xn = (a * xn + c) % m;
        fprintf(output,
                "%lld ",
                xn
        );
    }
}