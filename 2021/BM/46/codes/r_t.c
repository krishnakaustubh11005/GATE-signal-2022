#include "ee1205.h"
#include <stdio.h>

double f(double t) {
    return (t >= 0) ? t : 0;
}

int main() {
    // Generate x-axis.
    double* t = linspace(0, 2, 10000);
    // Open file.
    FILE* out;
    fopen_s(&out, "r_tcout.txt", "w");
    // Write data to file.
    for (size_t i = 0; i < 10000; i++) fprintf(out, "%lf ", f(t[i]));
    // Close file and free allocated memory.
    fclose(out);
    free(t);
    return 0;
}