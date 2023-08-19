#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define EXCEPTION "\033[1;31m%s\033[0m\n"

#define COMMAND_NOT_FOUND_EXCEPTION "incorrect command"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define NO_SOLUTION_EXCEPTION       "no solution"

#define OUTPUT_FILE "output.txt"

int isPositiveNumber(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    int num = atoi(str);
    if (num <= 0) {
        return 0;
    }
    return 1;
}

void incorrectCommand() {
    FILE *file;

    file = fopen(OUTPUT_FILE, "w");

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

bool checkPositive(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        if (array[i] <= 0) {
            return false;
        }
    }
    return true;
}

void checkCompatibility(int n, int a, int c, int x0, int m) {
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
        int cmin = -1, cmax = -1, m = -1;
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

        int array[] = {cmin, cmax, m};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool isCheckPositive = checkPositive(array, size);

        if (isCheckPositive) {
            printf("cmin=%d\ncmax=%d\nm=%d\n", cmin, cmax, m);
        } else {
            throwException();
        }
        return;
    }
        /**
         * TODO: get_c()
         */
//        get_c(cmin, cmax, m);
    else if (strcmp(token, "get_a") == 0) {
        int m = -1;
        while (token != NULL) {
            if (strncmp(token, "m=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                m = atoi(token + 2);
            }

            token = strtok(NULL, " ");
        }

        int array[] = {m};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool isCheckPositive = checkPositive(array, size);
        if (isCheckPositive) {
            printf("m=%d\n", m);
        } else {
            throwException();
        }
        /**
         * TODO: get_a()
         */
//        get_a(m);
    } else if (strcmp(token, "lcg") == 0) {
        int a = -1, x0 = -1, c = -1, m = -1, n = -1;
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

        int array[] = {a, x0, c, m, n};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool isCheckPositive = checkPositive(array, size);

        if (isCheckPositive) {
            printf("a=%d\nx0=%d\nc=%d\nm=%d\nn=%d\n", a, x0, c, m, n);
        } else {
            throwException();
        }
        /**
         * TODO: lcg()
         */
//        lcg(a, x0, c, m, n);
    } else if (strcmp(token, "test") == 0) {
        char *filename;
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (strncmp(token, "inp=", 4) == 0) {
                filename = token + 4;
            }
        }
        /**
         * TODO: test()
         */
//        test(filename);
    } else {
        incorrectCommand();
        printf(EXCEPTION,
               COMMAND_NOT_FOUND_EXCEPTION
        );
    }
}