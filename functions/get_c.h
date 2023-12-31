/**
 * @author:  https://github.com/Ossowitz
 * @author:  https://t.me/DispatcherServlet
 * @version: 1.0
 * TODO: implementation LKG
 */

#include <stdio.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define OUTPUT_FILE                 "output.txt"

/**
 *
 * @param:   a - numeric
 * @param:   b - numeric
 * @return:  Finding the least common divisor.
 * @see:     https://www.youtube.com/watch?v=cn2geFx5xAI
 */
unsigned long long areCoprime(unsigned long long a, unsigned long long b) {
    if (b == 0) {
        return a == 1;
    }
    return areCoprime(b, a % b);
}

/**
 * @param: cmin - numeric
 * @param: cmax - numeric
 * @param: m    - numeric
 * @brief: Pick up all c relatively prime to m, 0 < c < m, cmin <= c <= cmax.
 */
void get_c(unsigned long long cmin, unsigned long long cmax, unsigned long long m) {
    FILE *file = fopen(OUTPUT_FILE, "w");
    if (file != NULL) {
        for (unsigned long long c = cmin; c <= cmax; c++) {
            if (c > 0 && c < m && areCoprime(c, m)) {
                fprintf(file, "%d\n", c);
                printf("%d\n", c);
            }
        }
        fclose(file);
    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }
}