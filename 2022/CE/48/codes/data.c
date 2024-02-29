#include <stdio.h>
#include <math.h>

#define EULER_STEP_SIZE 0.2
#define NUM_POINTS_EULER ((6.0 - 1.0) / EULER_STEP_SIZE + 1)
#define ORIGINAL_STEP_SIZE 0.001
#define NUM_POINTS_ORIGINAL ((6.0 - 1.0) / ORIGINAL_STEP_SIZE + 1)

int main() {
    FILE *fp_original, *fp_euler;
    double t, y_original, y_euler;
    double x = 1.0, h = EULER_STEP_SIZE, y = 3.0; // initial condition y(1) = 3

    // Method 1: Original function
    fp_original = fopen("data1.txt", "w");
    if (fp_original == NULL) {
        printf("Error opening file data1.txt.\n");
        return 1;
    }
    fprintf(fp_original, "t\ty\n");
    for (t = 1.0; t <= 6.0; t += ORIGINAL_STEP_SIZE) {
        y_original = -5 * exp(-t + 1) + 4 + 4 * t;
        fprintf(fp_original, "%.3f\t%.6f\n", t, y_original);
    }
    fclose(fp_original);

    // Method 2: Euler's method
    fp_euler = fopen("data2.txt", "w");
    if (fp_euler == NULL) {
        printf("Error opening file data2.txt.\n");
        return 1;
    }
    fprintf(fp_euler, "x\ty\n");
    x = 1.0;
    y = 3.0;
    for (int i = 0; i < NUM_POINTS_EULER; i++) {
        fprintf(fp_euler, "%.2f\t%.6f\n", x, y);
        double derivative = 4 * (x + 2) - y;
        y += h * derivative;
        x += h;
    }
    fclose(fp_euler);

    return 0;
}

