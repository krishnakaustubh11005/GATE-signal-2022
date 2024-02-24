#include <stdio.h>
#include <math.h>

#define NUM_POINTS 1000

int main() {
    // Open file for writing
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    double x[NUM_POINTS];
    double y[NUM_POINTS];
    int i;

    // Generate x values
    for (i = 0; i < NUM_POINTS; i++) {
        x[i] = -2 * M_PI + i * (4 * M_PI / (NUM_POINTS - 1));
    }

    // Calculate y values
    for (i = 0; i < NUM_POINTS; i++) {
        y[i] = 0.5 * sin(2 * x[i]);
    }

    // Write x and y values to file
    for (i = 0; i < NUM_POINTS; i++) {
        fprintf(file, "%.8f %.8f\n", x[i], y[i]);
    }

    // Close file
    fclose(file);

    return 0;
}

