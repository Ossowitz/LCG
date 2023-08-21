/**
 * @author: https://github.com/Ossowitz
 * TODO: implementation LKG
 */

#include <stdio.h>

#include "../repository/parse_command.h"

#define EXCEPTION           "\033[1;31m%s\033[0m\n"
#define STATELESS           "\033[1;32m%s\033[0m\n"
#define OPEN_FILE_EXCEPTION "+ OPEN_FILE_EXCEPTION +"
#define COMPLETED           "+ APPLICATION_COMPLETED +"
#define FILE_OPENED         "+ FILE OPENED +"
//#define INPUT_FILE          "repository/input_get_c.txt"
//#define INPUT_FILE          "repository/input_get_a.txt"
//#define INPUT_FILE          "repository/input_lcg.txt"
#define INPUT_FILE          "repository/input_test.txt"

int main() {
    FILE *file = fopen(INPUT_FILE, "r");
    if (file != NULL) {
        printf(STATELESS,
               FILE_OPENED);
        char command[1000];
        if (fgets(command, sizeof(command), file) != NULL) {
            parseCommand(command);
        }
        fclose(file);
        printf(STATELESS,
               COMPLETED
        );
        return 0;
    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        exit(1);
    }
}