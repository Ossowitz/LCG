#include <stdio.h>

#define SEQUENCE_LENGTH 1000
#define WINDOW_LENGTH 1

static unsigned long long m = 4294967296;

// Линейно-конгруэнтный генератор
unsigned long lcg(unsigned long seed) {
    unsigned long a = 1664525;
    unsigned long c = 1013904223;
    return (a * seed + c) % m;
}

// Проверка последовательности на случайность с помощью критерия перестановок Дональда Кнута
int checkRandomness(unsigned long sequence[], int length) {
    int increasing = 0;
    int decreasing = 0;
    int extremes = 0;

    for (int i = WINDOW_LENGTH; i < length; i++) {
        int current = sequence[i];
        int previous = sequence[i - 1];
        if (current > previous) {
            increasing++;
        } else if (current < previous) {
            decreasing++;
        }

        if (current == 0 || current == m - 1) {
            extremes++;
        }
    }

    printf("increasing: %d\n", increasing);
    printf("decreasing: %d\n", decreasing);
    printf("extremes: %d\n", extremes);

    if (increasing == decreasing && extremes > 0) {
        return 1;  // Последовательность прошла проверку на случайность
    } else {
        return 0;  // Последовательность не прошла проверку на случайность
    }
}

int main() {
    unsigned long seed = 123456789;  // Начальное значение для ЛКГ
    unsigned long sequence[SEQUENCE_LENGTH];

    // Генерация последовательности чисел с помощью ЛКГ
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        seed = lcg(seed);
        sequence[i] = seed;
    }

    // Проверка случайности последовательности
    int isRandom = checkRandomness(sequence, SEQUENCE_LENGTH);
    if (isRandom) {
        printf("RANDOM\n");
    } else {
        printf("NOT_RANDOM\n");
    }

    return 0;
}