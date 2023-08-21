#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "../functions/get_c.h"
#include "../functions/get_a.h"
#include "../functions/lcg.h"
#include "../functions/test.h"

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define COMMAND_NOT_FOUND_EXCEPTION "incorrect command"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define NO_SOLUTION_EXCEPTION       "no solution"
#define OUTPUT_FILE                 "output.txt"

long long isPositiveNumber(const char *str) {
    for (long long i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    long long num = atoi(str);
    if (num <= 0) {
        return 0;
    }
    return 1;
}

void incorrectCommand() {
    FILE *file = fopen(OUTPUT_FILE, "w");

    if (file == NULL) {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }

    fprintf(file,
            COMMAND_NOT_FOUND_EXCEPTION
    );

    fclose(file);
}

void throwException() {
    FILE *file = fopen("output.txt", "w");
    printf(EXCEPTION,
           COMMAND_NOT_FOUND_EXCEPTION
    );
    fprintf(file,
            COMMAND_NOT_FOUND_EXCEPTION
    );
    fclose(file);
}

bool checkPositive(long long *array, size_t size) {
    for (long long i = 0; i < size; i++) {
        if (array[i] <= 0) {
            return false;
        }
    }
    return true;
}

void checkCompatibility(long long n, long long a, long long c, long long x0, long long m) {
    if (n == 0 || a >= m || c >= m || x0 >= m) {
        FILE *file = fopen("output.txt", "w");
        printf(EXCEPTION,
               NO_SOLUTION_EXCEPTION
        );
        fprintf(file,
                NO_SOLUTION_EXCEPTION
        );
        fclose(file);
    } else {
        return;
    }
}

void parseCommand(char *command) {
    char *token = strtok(command, " ");

    if (strcmp(token, "get_c") == 0) {
        long long cmin = -1, cmax = -1, m = -1;
        while (token != NULL) {
            if (strncmp(token, "cmin=", 5) == 0) {
                if (!isPositiveNumber(token + 5)) {
                    throwException();
                }
                cmin = atoi(token + 5);
            } else if (strncmp(token, "cmax=", 5) == 0) {
                if (!isPositiveNumber(token + 5)) {
                    throwException();
                }
                cmax = atoi(token + 5);
            } else if (strncmp(token, "m=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                m = atoi(token + 2);
            }

            token = strtok(NULL, " ");
        }

        long long array[] = {cmin, cmax, m};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool isCheckPositive = checkPositive(array, size);

        if (!isCheckPositive) {
            throwException();
        }
        get_c(cmin, cmax, m);
        return;
    } else if (strcmp(token, "get_a") == 0) {
        long long m = -1;
        while (token != NULL) {
            if (strncmp(token, "m=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                m = atoi(token + 2);
            }

            token = strtok(NULL, " ");
        }

        long long array[] = {m};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool isCheckPositive = checkPositive(array, size);
        if (!isCheckPositive) {
            throwException();
        }

        get_a(m);
    } else if (strcmp(token, "lcg") == 0) {
        long long a = -1, x0 = -1, c = -1, m = -1, n = -1;
        while (token != NULL) {
            if (strncmp(token, "a=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                a = atoi(token + 2);
            } else if (strncmp(token, "x0=", 3) == 0) {
                if (!isPositiveNumber(token + 3)) {
                    throwException();
                }
                x0 = atoi(token + 3);
            } else if (strncmp(token, "c=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                c = atoi(token + 2);
            } else if (strncmp(token, "m=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                m = atoi(token + 2);
            } else if (strncmp(token, "n=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                n = atoi(token + 2);
            }

            token = strtok(NULL, " ");
        }

        checkCompatibility(n, a, c, x0, m);

        long long array[] = {a, x0, c, m, n};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool isCheckPositive = checkPositive(array, size);

        if (!isCheckPositive) {
            throwException();
        }

        generateNum(a, x0, c, m, n);
    } else if (strcmp(token, "test") == 0) {
        char *filename = NULL;
        while (token != NULL) {
            if (strncmp(token, "inp=", 4) == 0) {
                filename = token + 4;
            }
            token = strtok(NULL, " ");
        }
        if (filename != NULL) {
            printf("%s\n", filename);
        } else {
            throwException();
        }

        test(filename);
    } else {
        incorrectCommand();
        printf(EXCEPTION,
               COMMAND_NOT_FOUND_EXCEPTION
        );
    }
}