#include <stdio.h>

// Function to calculate f(n) based on the given recurrence relations
int calculateF(int n) {
    if (n == 1) {
        return 1;
    } else if (n % 2 == 0) {
        return 2 * calculateF(n / 2) - 1;
    } else {
        return 2 * calculateF(n / 2) + 1;
    }
}

int main() {
    FILE *outputFile;
    outputFile = fopen("output.txt", "w");

    if (outputFile == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    for (int x = 1; x <= 50; x++) {
        int result = calculateF(x);
        fprintf(outputFile, "%d\n", result);
    }

    fclose(outputFile);

    printf("Values written to output.txt successfully.\n");

    return 0;
}

