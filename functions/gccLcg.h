#include <stdio.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define STATELESS                   "\033[1;32m%s\033[0m\n"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"

static long long m = 1 << 31;
static long long a = 1103515245;
static long long c = 12345;

long long lcg(long long seed) {
    return (a * seed + c) % m;
}

void lcgWriteToFile(char *filename, long long n) {
    FILE *output = fopen(filename, "w");

    if (output != NULL) {
        long long seed = 1 << 31;
        long long sequence[n];

        for (long long i = 0; i < n; i++) {
            seed = lcg(seed);
            sequence[i] = seed;
            fprintf(output,
                    "%lld ",
                    sequence[i]
            );
        }

    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }
}