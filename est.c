#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_positive_number(const char* str) {
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

int main() {
    char command[100] = "get_c cmin=10 cmax=20 m=5";
    char* token = strtok(command, " ");
    if (strcmp(token, "get_c") == 0) {
        int cmin = -1, cmax = -1, m = -1;
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (strncmp(token, "cmin=", 5) == 0) {
                if (!is_positive_number(token + 5)) {
                    FILE* file = fopen("output.txt", "w");
                    fprintf(file, "incorrect command");
                    fclose(file);
                    return 1;
                }
                cmin = atoi(token + 5);
            } else if (strncmp(token, "cmax=", 5) == 0) {
                if (!is_positive_number(token + 5)) {
                    FILE* file = fopen("output.txt", "w");
                    fprintf(file, "incorrect command");
                    fclose(file);
                    return 1;
                }
                cmax = atoi(token + 5);
            } else if (strncmp(token, "m=", 2) == 0) {
                if (!is_positive_number(token + 2)) {
                    FILE* file = fopen("output.txt", "w");
                    fprintf(file, "incorrect command");
                    fclose(file);
                    return 1;
                }
                m = atoi(token + 2);
            }
        }
    }
    return 0;
}

void parse_command1(char *command) {
    char *token;
    char *variables[3];

    token = strtok(command, " ");

    while (token != NULL) {
        if (strstr(token, "cmin=") != NULL) {
            variables[0] = strchr(token, '=') + 1;
        } else if (strstr(token, "cmax=") != NULL) {
            variables[1] = strchr(token, '=') + 1;
        } else if (strstr(token, "m=") != NULL) {
            variables[2] = strchr(token, '=') + 1;
        }

        token = strtok(NULL, " ");
    }

    // вывод значений переменных
    printf("cmin = %s\n", variables[0]);
    printf("cmax = %s\n", variables[1]);
    printf("m = %s\n", variables[2]);
}