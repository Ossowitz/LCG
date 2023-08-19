#include <string.h>
#include <stdlib.h>

#define EXCEPTION "\033[1;31m%s\033[0m\n"

#define COMMAND_NOT_FOUND "incorrect command"
#define OPEN_FILE_EXCEPTION "+ OPEN_FILE_EXCEPTION +"

#define OUTPUT_FILE "output.txt"

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

void parse_command(char *command) {
    char *token = strtok(command, " ");
    if (strcmp(token, "get_c") == 0) {
        int cmin, cmax, m;
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (strncmp(token, "cmin=", 5) == 0) {
                cmin = atoi(token + 5);
            } else if (strncmp(token, "cmax=", 5) == 0) {
                cmax = atoi(token + 5);
            } else if (strncmp(token, "m=", 2) == 0) {
                m = atoi(token + 2);
            }
        }
        /**
         * TODO: get_c()
         */
//        get_c(cmin, cmax, m);
    } else if (strcmp(token, "get_a") == 0) {
        int m;
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (strncmp(token, "m=", 2) == 0) {
                m = atoi(token + 2);
            }
        }
        /**
         * TODO: get_a()
         */
//        get_a(m);
    } else if (strcmp(token, "lcg") == 0) {
        int a, x0, c, m, n;
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (strncmp(token, "a=", 2) == 0) {
                a = atoi(token + 2);
            } else if (strncmp(token, "x0=", 3) == 0) {
                x0 = atoi(token + 3);
            } else if (strncmp(token, "c=", 2) == 0) {
                c = atoi(token + 2);
            } else if (strncmp(token, "m=", 2) == 0) {
                m = atoi(token + 2);
            } else if (strncmp(token, "n=", 2) == 0) {
                n = atoi(token + 2);
            }
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