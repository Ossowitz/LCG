#include <stdio.h>
#include <math.h>

#define SEQUENCE_LENGTH 100000

static long long m = 1 << 31;
static long long a = 1103515245;
static long long c = 12345;

// Линейно-конгруэнтный генератор
unsigned long lcg(long long seed) {
    return (a * seed + c) % m;
}

// Хи-квадрат
double chiSquareTest(long long *observed, long long *expected, long long categories) {
    double chiSquare = 0.0;

    for (long long i = 0; i < categories; i++) {
        chiSquare += pow(observed[i] - expected[i], 2) / expected[i];
    }

    return chiSquare;
}

// Проверка последовательности на случайность с помощью критерия перестановок Дональда Кнута
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

    printf("%f", squareTest);

//    if (increasing == decreasing) {
//        return 1;  // Последовательность прошла проверку на случайность
//    } else {
//        return 0;  // Последовательность не прошла проверку на случайность
//    }
}

int main() {
    long long seed = 1 << 31;  // Начальное значение для ЛКГ
    long long sequence[SEQUENCE_LENGTH];

    // Генерация последовательности чисел с помощью ЛКГ
    for (long long i = 0; i < SEQUENCE_LENGTH; i++) {
        seed = lcg(seed);
        sequence[i] = seed;
    }

    checkRandomness(sequence, SEQUENCE_LENGTH);

    // Проверка случайности последовательности
//    long long isRandom = checkRandomness(sequence, SEQUENCE_LENGTH);
//    if (isRandom) {
//        printf("RANDOM\n");
//    } else {
//        printf("NOT_RANDOM\n");
//    }

    return 0;
}