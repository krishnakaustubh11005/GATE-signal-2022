#include <stdio.h>
#include <math.h>

#define SIZE 6000

int main() {
    FILE *file_theoretical = fopen("data_theoretical.txt", "w");
    FILE *file_practical = fopen("data_practical.txt", "w");

    if (file_theoretical == NULL || file_practical == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    double t[SIZE];
    double theoretical[SIZE];
    double practical[SIZE];

    // Generate coordinates for theoretical displacement current
    for (int i = 0; i < SIZE; i++) {
        t[i] = 0.01 * i;
        theoretical[i] = sin(t[i] + M_PI / 2);
        fprintf(file_theoretical, "%.6f %.6f\n", t[i], theoretical[i]);
    }

    // Generate coordinates for practical displacement current
    double theoretical_max = 1.0; // Assuming theoretical range is [-1, 1]
    double practical_max = 1.0;    // Assuming practical range is [-1, 1]
    double scale_factor = theoretical_max / practical_max;
    double voltage = 0;
    for (int i = 0; i < SIZE; i++) {
        voltage = voltage + (1.0 / 1.0) * (theoretical[i] - voltage / 1.0) * (t[i] - t[i - 1]);
        practical[i] = voltage * scale_factor; // Scale practical values
        fprintf(file_practical, "%.6f %.6f\n", t[i], practical[i]);
    }

    fclose(file_theoretical);
    fclose(file_practical);

    printf("Data generated Successfully\n");

    return 0;
}

