/**
 * @author: https://github.com/Ossowitz
 * TODO: implementation LKG
 */

#include <stdio.h>
#include "parse_command.h"

#define EXCEPTION "\033[1;31m%s\033[0m\n"
#define STATELESS "\033[1;32m%s\033[0m\n"

#define OPEN_FILE_EXCEPTION "+ OPEN_FILE_EXCEPTION +"
#define COMPLETED "+ COMPLETED +"

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp != NULL) {
        char command[1000];
        if (fgets(command, sizeof(command), fp) != NULL) {
            parse_command(command);
        }
        fclose(fp);
        printf(STATELESS,
               COMPLETED
        );
    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
    }
}