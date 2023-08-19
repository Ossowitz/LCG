#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define EXCEPTION "\033[1;31m%s\033[0m\n"

#define COMMAND_NOT_FOUND "incorrect command"
#define OPEN_FILE_EXCEPTION "+ OPEN_FILE_EXCEPTION +"

#define OUTPUT_FILE "output.txt"

int is_positive_number(const char *str) {
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

void incorrect_command() {
    FILE *file;

    file = fopen(OUTPUT_FILE, "w");

    if (file == NULL) {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }

    fprintf(file,
            COMMAND_NOT_FOUND
    );

    fclose(file);
}

void throw_exception() {
    FILE *file = fopen("output.txt", "w");
    printf(EXCEPTION,
           COMMAND_NOT_FOUND
    );
    fprintf(file,
            COMMAND_NOT_FOUND
    );
    fclose(file);
}

bool check_positive(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        if (array[i] <= 0) {
            return false;
        }
    }
    return true;
}

void parse_command(char *command) {
    char *token = strtok(command, " ");

    if (strcmp(token, "get_c") == 0) {
        int cmin = -1, cmax = -1, m = -1;
        while (token != NULL) {
            if (strncmp(token, "cmin=", 5) == 0) {
                if (!is_positive_number(token + 5)) {
                    throw_exception();
                }
                cmin = atoi(token + 5);
            } else if (strncmp(token, "cmax=", 5) == 0) {
                if (!is_positive_number(token + 5)) {
                    throw_exception();
                }
                cmax = atoi(token + 5);
            } else if (strncmp(token, "m=", 2) == 0) {
                if (!is_positive_number(token + 2)) {
                    throw_exception();
                }
                m = atoi(token + 2);
            }

            token = strtok(NULL, " ");
        }

        int array[] = {cmin, cmax, m};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool checkPositive = check_positive(array, size);

        if (checkPositive) {
            printf("cmin=%d\ncmax=%d\nm=%d\n", cmin, cmax, m);
        } else {
            throw_exception();
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
                if (!is_positive_number(token + 2)) {
                    throw_exception();
                }
                m = atoi(token + 2);
            }

            token = strtok(NULL, " ");
        }

        int array[] = {m};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool checkPositive = check_positive(array, size);
        if (checkPositive) {
            printf("m=%d\n", m);
        } else {
            throw_exception();
        }
        /**
         * TODO: get_a()
         */
//        get_a(m);
    } else if (strcmp(token, "lcg") == 0) {
        int a = -1, x0 = -1, c = -1, m = -1, n = -1;
        while (token != NULL) {
            if (strncmp(token, "a=", 2) == 0) {
                if (!is_positive_number(token + 2)) {
                    throw_exception();
                }
                a = atoi(token + 2);
            } else if (strncmp(token, "x0=", 3) == 0) {
                if (!is_positive_number(token + 3)) {
                    throw_exception();
                }
                x0 = atoi(token + 3);
            } else if (strncmp(token, "c=", 2) == 0) {
                if (!is_positive_number(token + 2)) {
                    throw_exception();
                }
                c = atoi(token + 2);
            } else if (strncmp(token, "m=", 2) == 0) {
                if (!is_positive_number(token + 2)) {
                    throw_exception();
                }
                m = atoi(token + 2);
            } else if (strncmp(token, "n=", 2) == 0) {
                if (!is_positive_number(token + 2)) {
                    throw_exception();
                }
                n = atoi(token + 2);
            }

            token = strtok(NULL, " ");
        }

        int array[] = {a, x0, c, m, n};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool checkPositive = check_positive(array, size);
        if (checkPositive) {
            printf("a=%d\nx0=%d\nc=%d\nm=%d\nn=%d\n", a, x0, c, m, n);
        } else {
            throw_exception();
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
        incorrect_command();
        printf(EXCEPTION,
               COMMAND_NOT_FOUND
        );
    }
}