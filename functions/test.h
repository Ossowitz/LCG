#include <stdio.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define COMMAND_NOT_FOUND_EXCEPTION "incorrect command"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define NO_SOLUTION_EXCEPTION       "no solution"

void test(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file != NULL) {

        int capacity = 10;
        int count = 0;
        long long *array = malloc(capacity * sizeof(long long));

        long long num;
        while (fscanf(file, "%lld", &num) == 1) {
            if (count == capacity) {
                capacity *= 2;
                array = realloc(array, capacity * sizeof(long long));
            }
            array[count++] = num;
        }

    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }

    fclose(file);
}