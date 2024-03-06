#include <stdio.h>
#include <gsl/gsl_poly.h>

/*RUN -"gcc -o data1 data1.c -lgsl -lgslcblas -lm" to compile this program*/
int main(void) {
    int i, j;
    double kp, ki;
    double a[5]; 
    double z[8]; 

    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (freopen("data.txt", "w", stdout) == NULL) {
        perror("freopen() failed");
        return 1;
    }

    for (i = 0; i <= 20; i++) {
        kp = -1.0 + 0.5 * i; 

        for (j = 0; j <= 28; j++) {
            ki = 0.0 + 0.125 * j; 
            

            a[0] = 2 * ki;
            a[1] = 2 + 2 * kp;
            a[2] = 5;
            a[3] = 4;
            a[4] = 1;

            gsl_poly_complex_workspace *w = gsl_poly_complex_workspace_alloc(5);

            gsl_poly_complex_solve(a, 5, w, z);

            gsl_poly_complex_workspace_free(w);

            fprintf(fp, "For kp = %f and ki = %f:\n", kp, ki);
            for (int k = 0; k < 4; k++) {
                fprintf(fp, "Root %d: %+.18f %+.18f\n", k + 1, z[2 * k], z[2 * k + 1]);
            }
            fprintf(fp, "\n");
        }
    }

    fclose(fp);

    return 0;
}
