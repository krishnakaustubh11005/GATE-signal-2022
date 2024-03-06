#include "ee1205.h"
#include <stdio.h>
#include <math.h>

double f(double t) {
    if (t < 0) return 0;
    return -.1 + t + exp(-5 * t) * (.1 * cos(sqrt(65) * t) - .5 / sqrt(65) * sin(sqrt(65) * t));
}

int main() {
    // Generate x-axis.
    double* t = linspace(0, 2, 10000);
    // Open file.
    FILE* out;
    fopen_s(&out, "c_tcout.txt", "w");
    // Write data to file.
    for (size_t i = 0; i < 10000; i++) fprintf(out, "%lf ", f(t[i]));
    // Close file and free allocated memory.
    fclose(out);
    free(t);
    return 0;
}