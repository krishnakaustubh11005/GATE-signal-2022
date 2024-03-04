#include <stdio.h>
#include <math.h>

int main() {
    FILE *fp;
    fp = fopen("data77.dat", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Generate data
    for (int n = -3; n < 10; n++) {
        double x = (n + 1) * pow(1.5, n) * (n >= 0); // Unit step function u(n)
        fprintf(fp, "%5d %10.2lf\n", n, x);
    }

    fclose(fp);

    return 0;
}
