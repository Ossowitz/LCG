/**
 * @author:  https://github.com/Ossowitz
 * @author:  https://t.me/DispatcherServlet
 * @version: 1.0
 * TODO: implementation LKG
 */

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

/**
 * @param str - Number represented as a string
 * @return: This function checks if the given string is a positive number.
 */
unsigned long long strScreen(const char *str) {
    unsigned long long result = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            break;
        }
        i++;
    }

    return result;
}

/**
 * @param:  str - Number represented as a string
 * @return: This function checks if the given string is a positive number.
 */
unsigned long long isPositiveNumber(const char *str) {
    for (unsigned long long i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    unsigned long long num = strScreen(str);
    if (num <= 0) {
        return 0;
    }
    return 1;
}

/**
 * @brief: Function for throwing an exception associated with a file opening error.
 */
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

/**
 * @brief: A function to throw an exception if no solution is found.
 */
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

/**
 * @param:  array - numeric array
 * @param:  size  - size about numeric array
 * @return: This function checks if all elements of array are positive numbers.
 */
bool checkPositive(unsigned long long *array, size_t size) {
    for (unsigned long long i = 0; i < size; i++) {
        if (array[i] <= 0) {
            return false;
        }
    }
    return true;
}

/**
 * @param: n  - numeric
 * @param: a  - numeric
 * @param: c  - numeric
 * @param: x0 - numeric
 * @param: m  - numeric
 * @note:  0 <= a,x0,c,m,n      a,x0,c < m
 * @brief: This function is needed to validate input parameters.
 */
void checkCompatibility(unsigned long long n, unsigned long long a, unsigned long long c, unsigned long long x0,
                        unsigned long long m) {
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

/**
 * @param: command - Command that separates arguments
 * @brief: The call of a specific function depends on the value of the command.
 */
void parseCommand(char *command) {
    char *token = strtok(command, " ");

    if (strcmp(token, "get_c") == 0) {
        unsigned long long cmin = -1, cmax = -1, m = -1;
        while (token != NULL) {
            if (strncmp(token, "cmin=", 5) == 0) {
                if (!isPositiveNumber(token + 5)) {
                    throwException();
                }
                cmin = strScreen(token + 5);
            } else if (strncmp(token, "cmax=", 5) == 0) {
                if (!isPositiveNumber(token + 5)) {
                    throwException();
                }
                cmax = strScreen(token + 5);
            } else if (strncmp(token, "m=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                m = strScreen(token + 2);
            }
            token = strtok(NULL, " ");
        }

        unsigned long long array[] = {cmin, cmax, m};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool isCheckPositive = checkPositive(array, size);
        if (!isCheckPositive) {
            throwException();
        }
        get_c(cmin, cmax, m);
    } else if (strcmp(token, "get_a") == 0) {
        unsigned long long m = -1;
        while (token != NULL) {
            if (strncmp(token, "m=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                m = strScreen(token + 2);
            }
            token = strtok(NULL, " ");
        }

        unsigned long long array[] = {m};
        size_t size = sizeof(array) / sizeof(array[0]);

        bool isCheckPositive = checkPositive(array, size);
        if (!isCheckPositive) {
            throwException();
        }
        get_a(m);
    } else if (strcmp(token, "lcg") == 0) {
        unsigned long long a = -1, x0 = -1, c = -1, m = -1, n = -1;
        while (token != NULL) {
            if (strncmp(token, "a=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                a = strScreen(token + 2);
            } else if (strncmp(token, "x0=", 3) == 0) {
                if (!isPositiveNumber(token + 3)) {
                    throwException();
                }
                x0 = strScreen(token + 3);
            } else if (strncmp(token, "c=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                c = strScreen(token + 2);
            } else if (strncmp(token, "m=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                m = strScreen(token + 2);
            } else if (strncmp(token, "n=", 2) == 0) {
                if (!isPositiveNumber(token + 2)) {
                    throwException();
                }
                n = strScreen(token + 2);
            }
            token = strtok(NULL, " ");
        }

        checkCompatibility(n, a, c, x0, m);

        unsigned long long array[] = {a, x0, c, m, n};
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