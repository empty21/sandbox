#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INITIAL_LINE_LENGTH 1024
#define LINE_BUFFER_INCREMENT 1024

bool isIdentical(FILE *expectedOutputFile, FILE *outputFile) {
    if (expectedOutputFile == NULL || outputFile == NULL) {
        return false;
    }
    char ch1, ch2, ch1Old, ch2Old;

    while (ch1 != EOF && ch2 != EOF) {
        ch1 = fgetc(expectedOutputFile);
        while (ch1 == '\n' || ch1 == '\r') {
            ch1 = fgetc(expectedOutputFile);
        }
        if (ch1Old == ' ') {
            while (ch1 == ' ') {
                ch1 = fgetc(expectedOutputFile);
            }
        }

        ch2 = fgetc(outputFile);
        while (ch2 == '\n' || ch2 == '\r') {
            ch2 = fgetc(outputFile);
        }
        if (ch2Old == ' ') {
            while (ch2 == ' ') {
                ch2 = fgetc(outputFile);
            }
        }

        if (ch1 != ch2) return false;
        ch1Old = ch1;
        ch2Old = ch2;
    };

    return ch1 == EOF && ch2 == EOF;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("0");
        return 0;
    }

    FILE *expectedOutputFile = fopen(argv[1], "rb");
    FILE *outputFile = fopen(argv[2], "rb");

    bool result = isIdentical(expectedOutputFile, outputFile);
    printf("%d", result ? 1 : 0);

    fclose(expectedOutputFile);
    fclose(outputFile);
    return 0;
}
