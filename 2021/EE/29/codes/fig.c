#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double unit_step(double t) {
    if (t >= 0)
        return 1.0;
    else
        return 0.0;
}

double function(double t) {
    return (8.0 + 2.0 * exp(-10.0 * t)) * unit_step(t);
}

int main() {
    FILE *fp;
    fp = fopen("data.dat", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    for (double t = 0.0; t <= 10.0; t += 0.1) {
        fprintf(fp, "%lf %lf\n", t, function(t));
    }

    fclose(fp);
}

