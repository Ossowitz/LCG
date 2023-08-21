#include <stdio.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define STATELESS                   "\033[1;32m%s\033[0m\n"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define OUTPUT_FILE                 "output.txt"

static long long m = 1 << 31;
static long long a = 1103515245;
static long long c = 12345;

long long lcg(long long seed) {
    return (a * seed + c) % m;
}

void lcgWriteToFile(char *filename) {
    FILE *output = fopen(filename, "w");
    long long seed = 1 << 31;  // Начальное значение для ЛКГ

    if (output != NULL) {
        fprintf(output,
                "%lld ",
                lcg(seed)
        );
    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }
}