#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* linspace(double x1, double x2, int n) {
    double *x = calloc(n, sizeof(double));

    double step = (x2 - x1) / (double)(n - 1);

    for (int i = 0; i < n; i++) {
        x[i] = x1 + ((double)i * step);
    }

    return x;
}

double* expo(double x1, double x2, int n, double ind, double k){
    double *x = linspace(x1, x2, n);
    double *y = calloc(n, sizeof(double));
    for (int i = 0; i < n; i++) {
        y[i] = k*exp(ind*x[i]);
    }
    return y;
}

int main() {
    FILE *fp;
    fp = fopen("data.dat", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    double *x_array = linspace(0, 5, 9999);
    double *y_array = expo(0, 5, 9999, -4, 8);
    
    for (int i = 0; i < 9999; i++) {
        fprintf(fp, "%lf\t%lf\n", x_array[i], y_array[i]);
    }
    
    free(x_array);
    free(y_array);
    fclose(fp);
}

