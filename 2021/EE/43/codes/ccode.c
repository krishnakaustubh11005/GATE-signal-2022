#include <stdio.h>
#include <math.h>

#define NUM_POINTS 1000
#define PI 3.14159265358979323846

double my_function(double f) {
    if (f == 0) {
        return 1.0;
    }
    return pow(sin(PI * f) / (PI * f), 2);
}

int main() {
    FILE *fp;
    fp = fopen("data.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < NUM_POINTS; i++) {
        double f = -10.0 + (20.0 * i) / NUM_POINTS;
        fprintf(fp, "%.6f %.6f\n", f, my_function(f));
    }

    fclose(fp);
    return 0;
}
