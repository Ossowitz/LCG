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
 * @param: a  - numeric
 * @param: x0 - numeric
 * @param: c  - numeric
 * @param: m  - numeric
 * @param: n  - numeric
 * @see:   https://ru.wikipedia.org/wiki/%D0%9B%D0%B8%D0%BD%D0%B5%D0%B9%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BE%D0%BD%D0%B3%D1%80%D1%83%D1%8D%D0%BD%D1%82%D0%BD%D1%8B%D0%B9_%D0%BC%D0%B5%D1%82%D0%BE%D0%B4
 */
void generateNum(long long a, long long x0, long long c, long long m, long long n) {
    FILE *output = fopen(OUTPUT_FILE, "w");
    long long xn = x0;

    if (output == NULL) {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }

    for (int i = 0; i < n; i++) {
        xn = (a * xn + c) % m;
        fprintf(output,
                "%lld ",
                xn
        );
    }
}