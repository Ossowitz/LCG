#include <stdio.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define COMMAND_NOT_FOUND_EXCEPTION "incorrect command"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define NO_SOLUTION_EXCEPTION       "no solution"

#define SEQUENCE_LENGTH 10000

static long long m = 1 << 31;
static long long a = 1103515245;
static long long c = 12345;

// https://ru.wikipedia.org/wiki/%D0%9B%D0%B8%D0%BD%D0%B5%D0%B9%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BE%D0%BD%D0%B3%D1%80%D1%83%D1%8D%D0%BD%D1%82%D0%BD%D1%8B%D0%B9_%D0%BC%D0%B5%D1%82%D0%BE%D0%B4#:~:text=glibc%20(-,used%20by,-GCC)%5B10
long long glibcGeneratorByGcc(long long seed) {
    return (a * seed + c) % m;
}

void lcgWriteToFile(char *filename) {
    FILE *file = fopen(filename, "w");

    if (file != NULL) {
        long long seed = 1 << 31;
        long long sequence[SEQUENCE_LENGTH];

        for (long long i = 0; i < SEQUENCE_LENGTH; i++) {
            seed = glibcGeneratorByGcc(seed);
            sequence[i] = seed;
            fprintf(file,
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
    fclose(file);
}

void readFileToArray(FILE *file, long long int *array);

double chiSquareTest(long long *observed, long long *expected, long long categories) {
    double chiSquare = 0.0;

    for (long long i = 0; i < categories; i++) {
        chiSquare += pow(observed[i] - expected[i], 2) / expected[i];
    }

    return chiSquare;
}

void checkRandomness(long long sequence[], long long length) {
    long long increasing = 0;
    long long decreasing = 0;

    for (long long i = 1; i < length + 1; i += 2) {
        long long current = sequence[i];
        long long previous = sequence[i - 1];
        if (current > previous) {
            increasing++;
        } else if (current < previous) {
            decreasing++;
        }
    }

    printf("increasing: %lld\n", increasing);
    printf("decreasing: %lld\n", decreasing);

    long long observed[] = {increasing, decreasing};
    long long expected[] = {
            SEQUENCE_LENGTH / 4,
            SEQUENCE_LENGTH / 4
    };

    double squareTest = chiSquareTest(observed, expected, 2);

    printf("%f\n", squareTest);
}

void test(char *filename) {
    lcgWriteToFile(filename);

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        long long sequence[SEQUENCE_LENGTH];
        readFileToArray(file, sequence);

        checkRandomness(sequence, SEQUENCE_LENGTH);

    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }
    fclose(file);
}

void readFileToArray(FILE *file, long long int *array) {
    long long num;
    long long count = 0;
    while (fscanf(file, "%lld", &num) == 1) {
        array[count++] = num;
    }
}
