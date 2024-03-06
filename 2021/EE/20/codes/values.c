#include <stdio.h>
#include<math.h>
#include <float.h>

double mag_of_Vo(double w) {
    return 1 / sqrt(pow(0.000025, 2) * pow(w, 2) + pow((1 - (0.00000025 * pow(w, 2))), 2)) ;
}

int main() {
    FILE *fp;
    fp = fopen("data9.dat", "w");

    for (double w = 0; w <= 5000.0; w += 10) {
        fprintf(fp, "%e %e\n", w, mag_of_Vo(w));
    }

    fclose(fp);

    return 0;
}

