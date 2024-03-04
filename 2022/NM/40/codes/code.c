#include <stdio.h>
#include <math.h>

void linspace(int start, int stop, int step, float* x, float* y, int n) {
    for (int i = 0; i < n; ++i) {
        x[i] = (float)(start) + i * step/100.0;
        if(x[i] >= 0 && x[i] <= 0.25)
        y[i] = 25.6*x[i]; 
        if(x[i] >= 0.25 && x[i] <= 0.5 )
        y[i] = 6.4;
        if(x[i] >= 0.5 && x[i] <= 1)
        y[i] = 6.4 - 12.8*(x[i]-0.5);
    }
}

int main() {
    // Define the range and step size
    int start = 0;
    int stop = 100;
    int step = 1;

    // Calculate the number of values in the range
    int n = (stop - start) / step + 1;

    // Allocate arrays to store the generated values
    float x[n];
    float y[n];

    // Call the linespace function
    linspace(start, stop, step, x, y, n);

    // Save data to a file
    FILE* file = fopen("output.dat", "w");

    if (file != NULL) {
        for (int i = 0; i < n; ++i) {
            fprintf(file, "%f %f\n", x[i], y[i]);
        }

        fclose(file);
        printf("Data saved to 'output.dat'.\n");
    } else {
        printf("Error opening file for writing.\n");
    }

    return 0;
}

