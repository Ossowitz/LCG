/**
 * @author:  https://github.com/Ossowitz
 * @author:  https://t.me/DispatcherServlet
 * @version: 1.0
 * TODO: implementation LKG
 */

#include <stdio.h>
#include "math.h"

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define COMMAND_NOT_FOUND_EXCEPTION "incorrect command"
#define OPEN_FILE_EXCEPTION         "+ OPEN_FILE_EXCEPTION +"
#define NO_SOLUTION_EXCEPTION       "no solution"
#define OUTPUT_FILE                 "output.txt"

#define SEQUENCE_LENGTH 1000

static long long m = 1 << 31;
static long long a = 1103515245;
static long long c = 12345;

/**
 * @param:  seed - numeric, initial value in LKG
 * @return: pseudo-random number
 * @brief:  https://ru.wikipedia.org/wiki/%D0%9B%D0%B8%D0%BD%D0%B5%D0%B9%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BE%D0%BD%D0%B3%D1%80%D1%83%D1%8D%D0%BD%D1%82%D0%BD%D1%8B%D0%B9_%D0%BC%D0%B5%D1%82%D0%BE%D0%B4#:~:text=glibc%20(-,used%20by,-GCC)%5B10
 */
long long glibcGeneratorByGcc(long long seed) {
    return (a * seed + c) % m;
}

/**
 * @param: filename - file to which the entire sequence will be written
 * @note: Use this method call if there is no sequence in the file yet.\note
 *          LKG - source: glibc (used by GCC)
 * @see:  https://ru.wikipedia.org/wiki/%D0%9B%D0%B8%D0%BD%D0%B5%D0%B9%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BE%D0%BD%D0%B3%D1%80%D1%83%D1%8D%D0%BD%D1%82%D0%BD%D1%8B%D0%B9_%D0%BC%D0%B5%D1%82%D0%BE%D0%B4#:~:text=glibc%20(-,used%20by,-GCC)%5B10
 */
void lcgWriteToFile(char *filename) {
    FILE *file = fopen(filename, "w");

    if (file != NULL) {
        long long seed = 1 << 31;
        long long sequence[SEQUENCE_LENGTH];

        for (long long i = 0; i < SEQUENCE_LENGTH; i++) {
            seed = glibcGeneratorByGcc(seed);
            sequence[i] = seed;
            fprintf(file,
                    "%lld ",
                    sequence[i]
            );
        }

    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }
    fclose(file);
}

/**
 * @param: file  - file containing the sequence
 * @param: array - an array to hold the sequence
 */
void readFileToArray(FILE *file, long long int *array) {
    long long num;
    long long count = 0;
    while (fscanf(file, "%lld", &num) == 1) {
        array[count++] = num;
    }
}

/**
 * @param: observed     - this array contains the number of descending and the number of non-decreasing\note
 *      For example: {491, 509} or {242, 258}
 * @param: expected     - this array contains the real situation of decreasing and non-decreasing\note
 *      Always:      {500, 500} or {250, 250}
 * @param: categories   - this is how many numbers are in the subgroup
 * @return: chi-square (or xi :) )
 */
double chiSquareTest(long long *observed, long long *expected, long long categories) {
    double chiSquare = 0.0;
    for (long long i = 0; i < categories; i++) {
        chiSquare += pow(observed[i] - expected[i], 2) / expected[i];
    }
    return chiSquare;
}

/**
 * @param:   squareTest - chi-square that we calculated in the last function
 * @return:  a line with a message in which gap we are
 * @see:     http://kontromat.ru/?page_id=4200
 */
char *findBorders(double squareTest) {
    double grade1  = 0.02010;
    double grade5  = 0.1026;
    double grade25 = 0.5754;
    double grade50 = 1.386;
    double grade75 = 2.773;
    double grade95 = 5.991;
    double grade99 = 9.210;

    if (squareTest < grade1 || squareTest > grade99 || squareTest == INFINITY || squareTest == 0) {
        return "The sequence is not random. Observed and expected too different!";
    } else if (squareTest > grade1 && squareTest < grade5) {
        return "The sequence is not random. Xi-square between 1% - 5%";
    } else if (squareTest > grade5 && squareTest < grade25) {
        return "The sequence is random. Xi-square between 5% - 25%";
    } else if (squareTest > grade25 && squareTest < grade50) {
        return "The sequence is random. Xi-square between 25% - 50%";
    } else if (squareTest > grade50 && squareTest < grade75) {
        return "The sequence is random. Xi-square between 50% - 75%";
    } else if (squareTest > grade75 && squareTest < grade95) {
        return "The sequence is random. Xi-square between 75% - 95%";
    } else if (squareTest > grade95 && squareTest < grade99) {
        return "The sequence is random. Xi-square between 95% - 99%";
    }
}

/**
 * @param: squareTest - chi-square that we calculated in the last function
 * @note:  write the result of the chi-square calculation to a file
 */
void writeChiSquareResult(double squareTest) {
    FILE *output = fopen(OUTPUT_FILE, "w");
    char *borders = findBorders(squareTest);
    if (output != NULL) {
        fprintf(output,
                "%f\n%s",
                squareTest, borders
        );

        printf("%f\n", squareTest);
        printf("%s\n", borders);
    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }
}

/**
 * @param: sequence - numeric array
 * @param: length   - length of array
 * @see:   https://github.com/Ossowitz/LCG#readme
 */
void checkRandomness(long long sequence[], long long length) {
    long long increasing = 0;
    long long decreasing = 0;

    for (long long i = 1; i < length + 1; i += 2) {
        long long current = sequence[i];
        long long previous = sequence[i - 1];
        if (current > previous) {
            increasing++;
        } else if (current < previous) {
            decreasing++;
        }
    }

    printf("increasing: %lld\n", increasing);
    printf("decreasing: %lld\n", decreasing);

    long long observed[] = {increasing, decreasing};
    long long expected[] = {
            SEQUENCE_LENGTH / 4,
            SEQUENCE_LENGTH / 4
    };

    double squareTest = chiSquareTest(observed, expected, 2);

    writeChiSquareResult(squareTest);
}

/**
 * @param: filename - the file from which we will get the numbers.
 */
void test(char *filename) {
    /**
     * @note: Use this method call if there is no sequence in the file yet!
     */
    lcgWriteToFile(filename);

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        long long sequence[SEQUENCE_LENGTH];
        readFileToArray(file, sequence);

        checkRandomness(sequence, SEQUENCE_LENGTH);

    } else {
        printf(EXCEPTION,
               OPEN_FILE_EXCEPTION
        );
        return;
    }
    fclose(file);
}